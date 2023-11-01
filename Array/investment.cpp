#include <bits/stdc++.h>
using namespace std;

string convertToIndianNumber(int number)
{
    if (number == 0)
    {
        return "0";
    }

    int crore = number / 10000000;
    int lakh = (number / 100000) % 100;
    int thousand = (number / 1000) % 100;
    int units = number % 1000;

    string result;

    if (crore > 0)
    {
        result += to_string(crore) + " Crore, ";
    }
    if (lakh > 0)
    {
        result += to_string(lakh) + " Lakh, ";
    }
    if (thousand > 0)
    {
        result += to_string(thousand) + " Thousand, ";
    }
    if (units > 0)
    {
        result += to_string(units);
    }

    return result;
}

void print_text(string text, long long val, long long present_value)
{
    cout << text << " - " << val << " ( " << convertToIndianNumber(val) << " ) "
         << "Present value " << present_value << " ( " << convertToIndianNumber(present_value) << " ) \n"
         << endl;
}

void print_text_precentage(string text, double val)
{
    cout << text << " - " << val << " % \n"
         << endl;
}
void print_bike_loan_details(double total_value, double intrest,double emi,string activation_type){

    cout<< "<---------- "<< activation_type << " ---------->"<<endl;
    cout<< "Total value of the bike after "<<time<< " years"<<endl; 
    cout<< "Total intrest Valur "<<intrest<<endl;
    cout<<"EMI incurred"<<emi<<endl;
}

double present_value(long long future_val, int time, double depreciation = 6.0)
{
    double present_val = (double)future_val / pow((1 + (0.01 * depreciation)), time);
    return present_val;
}

pair<long long, long long> compounded_value(int amount, double roi, int time)
{
    pair<long long, long long> ans;
    int no_of_months = time * 12;
    ans.first = amount * no_of_months;
    ans.second = amount * ((pow((1 + roi), no_of_months) - 1) / roi) * (1 + roi);
    return ans;
}
long long future_value(double amount, double roi, int n)
{
    amount = amount * 12;
    roi = roi * 12;
    return amount * (pow(1 + roi, n));
}

void step_up_calculation(double amount, double step_up_rate, double roi, int n)
{
    long long total_investment = amount * 12;
    long long total_wealth = future_value(amount, roi, n);
    pair<long long, long long> ans;
    for (int i = 1; i < n; i++)
    {
        long long curr_val = amount * 12 * (1 + step_up_rate);
        total_investment += curr_val;
        amount = amount * (1 + step_up_rate);
       // cout << i << " " << amount << " " << n - i << " " << future_value(amount, roi, n - i) << endl;
        if (i != n - 1)
        {
            total_wealth += future_value(amount, roi, n - i);
        }
        else
        {
            total_wealth += amount * 12;
        }
    }
    cout << "\n<------ STEP UP CALCULATION ----->\n"
         << endl;
    print_text("Actual money invested", total_investment, present_value(total_investment, n));
    print_text("Compounded Money (Future value)", total_wealth, present_value(total_wealth, n));
    double wealth_created_by = (double)(total_wealth - total_investment) / total_investment * 100;

    print_text_precentage("Wealth created", wealth_created_by);
}
void simple_interest_bike_loan(double on_road_price_of_bike,int time, double rate_of_intrest = 9.35){
    rate_of_intrest = rate_of_intrest/100;
    double total_amount_of_bike = on_road_price_of_bike*(1+(rate_of_intrest*time));
    double intrest = on_road_price_of_bike*rate_of_intrest*time;
    double emi = total_amount_of_bike/(12*time);
    print_bike_loan_details(total_amount_of_bike,intrest,emi)
   
}
void diminsing_asset_way(double on_road_price,int time){
    
}

// store the value,intrest and EMI in vector;

 //diminshing asset method
    double diminished_captial = on_road_price_of_bike


void bike_laon(){
    double on_road_price_of_bike ;
    cout<< "Enter the on-raod price of the bike"<<endl;
    cin>> on_road_price_of_bike;
    cout<<"Enter the number of years you want to have the loans"<<endl;
    int time;
    cin>> time;
    double rate_of_intrest =9.35;
    simple_interest_bike_loan();
    char continue = 'n';
   
    while(continue != 'Y' || continue != 'y'){
         int n;
         cout<<"1. Simple interest \n";
         cout<<"2. Diminshing intrest method \n";
         cout<<"3. Compound intrest Value \n";
         cout<<"Select the option to continue"<<endl;
         cin>> n;

         switch (n)
         {
         case 1: simple_interest_bike_loan(on_road_price_of_bike,time);
            break;
         
         default:
            break;
         }
    }
   


}


int main()
{
    int amount;
    cout << "Enter the amount you would invest monthly" << endl;
    cin >> amount;
    int time;
    cout << "Enter the time in year that you would invest monthly" << endl;
    cin >> time;
    double roi = 0.10 / 12;
    double step_up_rate = 0.15;
    pair<long long, long long> compounded_wealth = compounded_value(amount, roi, time);
    pair<long long, long long> previous_year_wealth = compounded_value(amount, roi, time - 1);
    // pair<long long, long long> step_up_wealth = step_up_calculation(amount,step_up_rate,roi,time);
    double wealth_created_by = (double)(compounded_wealth.second - compounded_wealth.first) / compounded_wealth.first * 100;
    double wealth_increase = (double)(compounded_wealth.second - previous_year_wealth.second) / previous_year_wealth.second * 100;
    // FV = P * [(1 + r)^n - 1] / r * (1 + b)^n
    // long long step_up_future_value = amount * ((pow((1+roi),no_of_months)-1)/roi) * ((pow((1+step_up_rate),no_of_months)-1)/step_up_rate);
    cout << "\n<----- INSIGHTS ---->\n \n";

    print_text("Actual money invested", compounded_wealth.first, present_value(compounded_wealth.first, time));
    print_text("Compounded Money (Future value)", compounded_wealth.second, present_value(compounded_wealth.second, time));
    print_text("Previous year's compounded money value", previous_year_wealth.second, present_value(previous_year_wealth.second, time));
    step_up_calculation(amount, step_up_rate, roi, time);

    cout << "<-- Normal case without step-up --->" << endl;
    print_text_precentage("Wealth created", wealth_created_by);
    print_text_precentage("Wealth increased from previous year", wealth_increase);
    return 0;
}
