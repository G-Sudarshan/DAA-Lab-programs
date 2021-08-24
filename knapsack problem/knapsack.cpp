/*

    AUTHOR: G SUDARSHAN
    Github: github.com/g-sudarshan
    Title: Knapsack problem
    Date: 19-08-2021

*/

#include<iostream>

using namespace std;


void merge(float a[], int beg, int mid, int end, int n, float profit[], float weight[])
{
    int i=beg,j=mid+1,k,index = beg;
    float temp_ratio[n];
    float temp_profit[n];
    float temp_weight[n];

    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
        {
            temp_ratio[index] = a[i];
            temp_profit[index] = profit[i];
            temp_weight[index] = weight[i];
            i = i+1;
        }
        else
        {
            temp_ratio[index] = a[j];
            temp_profit[index] = profit[j];
            temp_weight[index] = weight[j];
            j = j+1;
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp_ratio[index] = a[j];
            temp_profit[index] = profit[j];
            temp_weight[index] = weight[j];
            index++;
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp_ratio[index] = a[i];
            temp_profit[index] = profit[i];
            temp_weight[index] = weight[i];
            index++;
            i++;
        }
    }
    k = beg;
    while(k<index)
    {
        a[k]=temp_ratio[k];
        profit[k]=temp_profit[k];
        weight[k]=temp_weight[k];
        k++;
    }
}

void mergeSort(float a[], int beg, int end, int n, float b[], float c[])
{
    int mid;

    if(beg<end)
    {
        mid = (beg+end)/2;
        mergeSort(a,beg,mid,n,b,c);
        mergeSort(a,mid+1,end,n,b,c);
        merge(a,beg,mid,end,n,b,c);
    }

}

int main(){

    int capacity, n, i, j;

    cout << "Enter capacity of knapsack: "<<endl;
    cin >> capacity;
    cout << "Enter no. of items: "<<endl;
    cin >> n;

    float profit[n], weight[n], pw_ratio[n];

    for(int i = 0 ; i < n ; i++){
        cout << "\nEnter profit of item " << (i+1) << ": ";
        cin >> profit[i];
        cout << "\nEnter weight of item " << (i+1) << ": ";
        cin >> weight[i];

        pw_ratio[i] = profit[i] / weight[i];
    }


    mergeSort(pw_ratio, 0, n, n, profit, weight);



    for(int i = 0 ; i < n ; i++){
        cout << pw_ratio[i] << " | " << profit[i] << " | " << weight[i] << endl;
    }


    return 0;
}
