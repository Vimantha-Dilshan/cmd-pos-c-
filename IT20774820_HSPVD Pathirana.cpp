#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
// IT20774820 - H.S.P.V.D Pathirana
	
	string customer;
	int customer_code;
	float total_bill_after_tax,final_bill;
	int random_no;
	
	float total(int u, float v);
	float total_price_discount_c(float to_price);
	float qty_discount_c(int qty, float to_price);
	float discount_acc(float total_item_discount);
	float tax_amount(float total_bill_after_discount_price );
	
	string acc_type_c(int user_id);
	string luckey_no();
		
int main ()
{
	int user_id,qty;
	char next_item;
	float item_price,total_price_discount,sum_total_discount,qty_discount,sum_total_price,total_discount;
	float total_item_discount,acc_type_discount,total_bill_after_discount_price,tax_code,discount,discount_qty,discount_customer,tax_rate;
	float total_price,acc_type;
	
	cout<<" ===================================== "<< endl;
	cout<<"         ~ TRINGO RETAILERS ~          "<< endl;
	cout<<" ===================================== "<< endl;
	cout<<"                                       "<< endl;
	cout<<" CUSTOMER ID          :          ";
	cin>>user_id;
	cout<<"                                 "<< endl;
	//User_ID input
	
	do 
	{
		cout<<" -------------------------------------"<< endl;
	    cout<<" QUANTITY             :           ";
		cin>>qty;
		
		cout<<" ITEM PRICE           :           ";
		cin>>item_price;
		
		cout<<" PRESS N TO ADD NEW   :           ";
		cin>>next_item;
		cout<<" -------------------------------------"<< endl;
		cout<<"     "<< endl;
		//User Inputs
		
		total_price = total (qty,item_price);
		sum_total_price = sum_total_price + total_price ;
		total_price_discount = total_price_discount_c(total_price);
		qty_discount = qty_discount_c (qty,total_price);
		total_discount = total_price_discount + qty_discount;
		sum_total_discount = sum_total_discount + total_discount;
	}
	while(next_item == 'N');
	//End of do-while loop _ next item
	
	total_item_discount = sum_total_price - sum_total_discount;
	//Total item discount
	
	acc_type_c(user_id);
	acc_type_discount = discount_acc (total_item_discount);
	total_bill_after_discount_price = total_item_discount - acc_type_discount;
	tax_code = tax_amount (total_bill_after_discount_price);
	//Calling Functions
	
	total_bill_after_tax = total_bill_after_discount_price + tax_code;
	//Total Billing amount after Tax
	
	cout<<" =====================================  "<< endl;
	cout<<"|                                     |"<< endl; //Line Spacing
	cout<<" ITEM DISCOUNT             :  "<<total_item_discount<< endl;
	cout<<"|                                     |"<< endl; //Line Spacing
	cout<<" TOTAL WITH DISCOUNT PRICE :  "<<total_bill_after_discount_price<< endl;
	cout<<"|                                     |"<< endl; //Line Spacing
	cout<<" TOTAL BILL + TAX          :  "<<total_bill_after_tax<< endl;
	cout<<"|                                     |"<< endl; //Line Spacing
	cout<<" =====================================  "<< endl;
	
	luckey_no ();
	return 0;
}
float total(int u, float v)
{
	return u*v;
} //Total Price

float total_price_discount_c (float to_price)
{
	float discount;
	if(to_price>10000)
	{
		discount = to_price*10/100;
	}
	else if(to_price<=10000 & to_price>5000)
	{
		discount = to_price*5/100;
	}
	else if(to_price<=5000 & to_price>3000)
	{
		discount = to_price*3/100;
	}
	else if(to_price<=3000 & to_price>2000)
	{
		discount = to_price*2/100;
	}
	return discount;
} //Total Price Discount

float qty_discount_c (int qty,float to_price)
{
	float discount_qty;
	
	if(qty>15)
	{
		discount_qty = to_price*3/100;
	}
	else if(qty<=15 & qty>10)
	{
		discount_qty = to_price*2/100;
	}
	else if(qty<=10 & qty>5)
	{
		discount_qty = to_price*1/100;
	}
	return discount_qty;
} //Quantity Discount

string acc_type_c(int user_id)
{
   	   if(user_id>1099 & user_id<1200)
	   {
	   	customer = "Premium";
		customer_code = 1;
	   } //Platinum member confirmation
	   else if(user_id>1199 & user_id<1300)
	   {
	   	customer = "Gold";
		customer_code = 2;
	   } //Gold member confirmation
	   else if(user_id>1299 & user_id<1400)
	   {
	   	 customer = "Silver";
		 customer_code = 3;
	   } //Silver member confirmation
	    return customer;
} //Customer type

float discount_acc (float total_item_discount)
{
	float discount_customer;
	
    if (customer_code == 1)
    {
    	discount_customer = total_item_discount*10/100;
	} //Platinum member discount
	else if (customer_code == 2)
	{
		discount_customer = total_item_discount*5/100;
	} //Gold member discount
	else if (customer_code == 3)
	{
		discount_customer = total_item_discount*3/100;
	} //Silver member discount
	return discount_customer;
}//Discount according to customer type

float tax_amount(float total_bill_after_discount_price )
{
	float tax_rate;
		
	if (total_bill_after_discount_price>50000)
	{
		tax_rate = total_bill_after_discount_price*10/100;
	}
	else if (total_bill_after_discount_price>20000)
	{
		tax_rate = total_bill_after_discount_price*5/100;
	}
	else if (total_bill_after_discount_price>10000)
	{
		tax_rate = total_bill_after_discount_price*3/100;
	}
	return tax_rate;
}//Tax Amount for Customer

string luckey_no ()
{
	srand (time(NULL));
	random_no =(rand()%10);
	
	if (total_bill_after_tax>10000)
	{
		cout<<"     "<< endl;
		cout<<"       YOUR LUCKEY NUMBER  :   "<<random_no<<endl;
		cout<<"     "<< endl;
		if (random_no == 7)
		{
			final_bill = total_bill_after_tax*30/100;
			final_bill = total_bill_after_tax - final_bill;
			cout<<"     "<< endl; //Line Spacing
			
		}
		else
		{
			cout<<" ===================================== "<< endl;
			cout<<"|                                     |"<< endl; 
			cout<<"|    ....YOU LOSS, TRY AGAIN!....     |"<< endl;
			cout<<"|                                     |"<< endl;
		}
		cout<<" ===================================== "<< endl;
		cout<<"|                                     |"<< endl;
		cout<<"|   ....THANK YOU! - COME AGAIN....   |"<< endl;
		cout<<"|                                     |"<< endl;
		cout<<" ===================================== "<< endl;
	}
} //Luckey Number generating

 

	

		
	
	