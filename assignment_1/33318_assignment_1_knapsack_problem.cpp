/*

Title: Fractional Knapsack 
Name: Sudarshan Gawale
Roll No.: 33318

*/

#include <iostream>
using namespace std;
//class to store items 
class item_struct{
      public:
        int id;
        double profit,weight;
        double ratio;
    };

//------------Merge sort---------------------------------------------------
void merge(item_struct *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //divide array into left and right subarrays
   //size of left and right sub-arrays
   nl = m-l+1; 
   nr = r-m;
   item_struct larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;

   //marge temp arrays to real array
   while(i < nl && j<nr) {
      //sorting w.r.t. ratio
      if(larr[i].ratio >= rarr[j].ratio) {
         //largest element will be placed before smallest as descending order
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //remaining elements in leftArray
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //remaining elements in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(item_struct *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
//-----------------------Knapsack -------------------------------------------
void knapsack(item_struct * item, int n, int c)
{
   double totalWeight = 0, totalProfit = 0;
   int i;
   item_struct result[n]; //to store the selected items

   //sort the items by profit/weight ratio in descending order
   mergeSort(item,0,n-1);

   //looping through all elements
   for(i=0;i<n;i++)
   {
      //check if the entire item can be used
      if(totalWeight + item[i].weight <= c)
      {
         //add the total weight and profit to final profit
         totalWeight+=item[i].weight;
         totalProfit+=item[i].profit;
         //save the item in result array
         result[i] = item[i];
      }

      //if the weight of item is more than capacity
      else
      {
         //calculte the remaining capacity 
         double remain = c - totalWeight;
         //update the final weight by adding remaining weight
         totalWeight+= remain;
         //update the final profit by adding the profit of item by selecting remaining weight
         totalProfit+= item[i].profit * remain/item[i].weight;

         //save item with selected weight and obtained profit in result array
         result[i].id = item[i].id;
         result[i].weight = remain;
         result[i].profit = item[i].profit * remain/item[i].weight;
         break; //stop 
      }

   }

   //display result
   cout<<"======================================================================"<<endl;
   cout<<"Items with selected weight and earned profit"<<endl;
   cout<<"ID."<<"\tWeight"<<"\tProfit"<<endl;
   for(int j=0;j<i;j++)
   {
      cout<<result[j].id<<"\t"<<result[j].weight<<"\t"<<result[j].profit<<endl;
   }
   cout<<"======================================================================"<<endl;
   cout<<"Total Weight::"<<totalWeight<<endl<<"Total Profit earned::"<<totalProfit<<endl;
   cout<<"======================================================================"<<endl;

    
}
//-----------------------Driver function------------------------------
int main() {
    int n;
    double c;
    cout<<"=========Knapsack Problem======================================="<<endl;
    cout<<"Enter number of items:";
    cin>>n;
    item_struct item[n];
    cout<<"Enter weight and profit for each item:"<<endl;
    for(int i=0;i<n;i++)
    {
        item[i].id = i+1;
        cout<<"Item "<<i+1<<endl;
        cout<<"Weight:";
        cin>>item[i].weight;
        cout<<"Profit:";
        cin>>item[i].profit;
        item[i].ratio = item[i].profit/item[i].weight;
        //validation for negative values
        if(item[i].weight<0 || item[i].profit<0)
        {
           cout<<"Please enter positive values"<<endl;
           i--;
        }
        
    }
    cout<<"Enter capacity of container:";
    cin>>c;
    //display entered values to user
    cout<<"======================================================================"<<endl;
    cout<<"Values entered are::"<<endl;
    cout<<"ID\tWeight\tProfit"<<endl;
    for(int i=0;i<n;i++)
    {
       cout<<item[i].id<<"\t"<<item[i].weight<<"\t"<<item[i].profit<<endl;
    }

    knapsack(item,n,c);
    return 0;
}
