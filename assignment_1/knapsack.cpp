/*

Name: Sudarshan Gawale
Roll no.: 33318
Btach: L11
Assignment: 2

*/

#include<bits/stdc++.h>
using namespace std;

double fractional_Knapsack(int W, int n, vector<int>&  weights, vector<int>& values);
int bounded_Knapsack(int W, int n, vector<int>&  weights, vector<int>& values);
void compare_Greedy_And_DP(int W, int n, vector<int>&  weights, vector<int>& values);

int main() {

    while(true) {
        
        cout << "\n ----- MENU DRIVEN PROGRAM ----- \n";

        int W;
        cout << "\nEnter capacity of the Knapsack: ";
        cin >> W;

        int n;
        cout << "Enter number of items: ";
        cin >> n;
        
        vector<int> weights;
        cout << "Enter weights of n items: ";
        for(int i=0; i<n; i++) {
            int wt;
            cin >> wt;
            weights.push_back(wt);
        }

        vector<int> values;
        cout << "Enter price of n items: ";
        for(int i=0; i<n; i++) {
            int price;
            cin >> price;
            values.push_back(price);
        }    

        while(true) {

            cout << "1. Fractional Knapsack   2. 0/1 Knapsack   3. Compare greedy and dp (0/1 knapsack)\n";
            cout << "Enter your choice: ";
            int option;
            cin >> option;

            switch (option) {
                case 1: fractional_Knapsack(W, n, weights, values);
                        break;
                case 2: bounded_Knapsack(W, n, weights, values);
                        break;
                case 3: compare_Greedy_And_DP(W, n, weights, values);
                        break;
                default: cout << "Invalid choice!\n";
                        break;
            }

            char ch;
            cout << "Do you wish to continue for same data (Y/N): ";
            cin >> ch;

            if(ch == 'N' || ch == 'n') {
                break;
            }
        }
        char choice;
        cout << "Do you wish to continue for another data (Y/N): ";
        cin >> choice;

        if(choice != 'Y' && choice != 'y') {
            cout << "\n----- Thank you! ----";
            break;
        }
    }
    return 0;
}

double fractional_Knapsack(int W, int n, vector<int>&  weights, vector<int>& values) {
    vector< pair <double, int> > pricePerKg;  // pair: value_per_kg & respective_index
    for(int i=0; i<n; i++) {
        double average = values[i]/(double)weights[i];
        pricePerKg.push_back(make_pair(average, i));
    }
    sort(pricePerKg.begin(), pricePerKg.end());
    double profit = 0;
    double capacity = 0;
    for(int i=n-1; i>=0; i--) {
        int index = pricePerKg[i].second;
        double p = pricePerKg[i].first;
        if(capacity == W) {
            break;
        }
        if(W >= capacity+weights[index]) {
            profit += values[index];
            capacity += weights[index];
        }
        else {
            double total_wt = 0;
            while(capacity+1 <= W) {
                capacity += 1;
                total_wt += 1;
                profit += p;
                if(total_wt == weights[index]) {
                    break;
                }
            }
            break;
        }
    }
    cout << "Profit using fractional knapsack (greedy approach): " << profit << endl;
    return profit;
}
int bounded_Knapsack(int W, int n, vector<int>&  weights, vector<int>& values) {
    int dp[n+1][W+1];
	memset(dp, -1, sizeof(dp));
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=W; j++) {
			if(i*j == 0) {
				dp[i][j] = 0;
			} 
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=W; j++) {
			if(weights[i-1] <= j) {
				dp[i][j] = max(values[i-1]+dp[i-1][j-weights[i-1]], dp[i-1][j]);
			} 
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
    cout << "Profit using Dynamic Programming approach: " << dp[n][W] << endl;
	return dp[n][W];
}
void compare_Greedy_And_DP(int W, int n, vector<int>&  weights, vector<int>& values) {
    vector< pair <double, int> > pricePerKg;  // pair: value_per_kg & respective_index
    for(int i=0; i<n; i++) {
        double average = values[i]/(double)weights[i];
        pricePerKg.push_back(make_pair(average, i));
    }
    sort(pricePerKg.begin(), pricePerKg.end());
    double profit = 0;
    double capacity = 0;
    for(int i=n-1; i>=0; i--) {
        
        int index = pricePerKg[i].second;
        double p = pricePerKg[i].first;
        if(capacity == W) {
            break;
        }
        if(W >= capacity+weights[index]) {
            profit += values[index];
            capacity += weights[index];
        }
        
    }
    cout << "Profit using greedy strategy: " << profit << endl;
    int a = bounded_Knapsack(W, n, weights, values);
    
    if(a > profit) {
        cout << "DP gives better profit\n";
        cout << "Greedy strategy does not necessarily yield an optimal solution over a dynamic programming approach.\n";
    }
    else if(a < profit) {
        cout << "Greedy approach gives better solution\n";
    }
    else {
        cout << "Same profits for both the methods\n";
    }
    
    //return profit;
}

// output:
/*

 ----- MENU DRIVEN PROGRAM ----- 

Enter capacity of the Knapsack: 10
Enter number of items: 3
Enter weights of n items: 1 5 10
Enter price of n items: 2 4 10

1. Fractional Knapsack   2. 0/1 Knapsack   3. Compare greedy and dp (0/1 knapsack)
Enter your choice: 1
Profit using fractional knapsack (greedy approach): 11

Do you wish to continue for same data (Y/N): y

1. Fractional Knapsack   2. 0/1 Knapsack   3. Compare greedy and dp (0/1 knapsack)
Enter your choice: 2
Profit using Dynamic Programming approach: 10

Do you wish to continue for same data (Y/N): y

1. Fractional Knapsack   2. 0/1 Knapsack   3. Compare greedy and dp (0/1 knapsack)
Enter your choice: 3
Profit using greedy strategy: 6
Profit using Dynamic Programming approach: 10
DP gives better profit
Greedy strategy does not necessarily yield an optimal solution over a dynamic programming approach.

Do you wish to continue for same data (Y/N): n
Do you wish to continue for another data (Y/N): y 

 ----- MENU DRIVEN PROGRAM ----- 

Enter capacity of the Knapsack: 60
Enter number of items: 7
Enter weights of n items: 12 15 30 35 45 3 1
Enter price of n items: 24 30 60 40 52 6 1

1. Fractional Knapsack   2. 0/1 Knapsack   3. Compare greedy and dp (0/1 knapsack)
Enter your choice: 1
Profit using fractional knapsack (greedy approach): 120

Do you wish to continue for same data (Y/N): y

1. Fractional Knapsack   2. 0/1 Knapsack   3. Compare greedy and dp (0/1 knapsack)
Enter your choice: 2
Profit using Dynamic Programming approach: 120

Do you wish to continue for same data (Y/N): y

1. Fractional Knapsack   2. 0/1 Knapsack   3. Compare greedy and dp (0/1 knapsack)
Enter your choice: 3
Profit using greedy strategy: 120
Profit using Dynamic Programming approach: 120
Same profits for both the methods

Do you wish to continue for same data (Y/N): n
Do you wish to continue for another data (Y/N): y

 ----- MENU DRIVEN PROGRAM ----- 

Enter capacity of the Knapsack: 50
Enter number of items: 3
Enter weights of n items: 10 20 40
Enter price of n items: 60 100 120

1. Fractional Knapsack   2. 0/1 Knapsack   3. Compare greedy and dp (0/1 knapsack)
Enter your choice: 1
Profit using fractional knapsack (greedy approach): 220

Do you wish to continue for same data (Y/N): y

1. Fractional Knapsack   2. 0/1 Knapsack   3. Compare greedy and dp (0/1 knapsack)
Enter your choice: 2
Profit using Dynamic Programming approach: 180

Do you wish to continue for same data (Y/N): y

1. Fractional Knapsack   2. 0/1 Knapsack   3. Compare greedy and dp (0/1 knapsack)
Enter your choice: 3
Profit using greedy strategy: 160
Profit using Dynamic Programming approach: 180
DP gives better profit
Greedy strategy does not necessarily yield an optimal solution over a dynamic programming approach.

Do you wish to continue for same data (Y/N): n
Do you wish to continue for another data (Y/N): n

----- Thank you! ----
*/