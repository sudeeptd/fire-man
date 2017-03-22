#include "additional_functions.h"
#include <bits/stdc++.h>
using namespace std;

void generate_input_2()
{
	srand(time(NULL));
	ofstream file1 ("girls.txt");
	int j,t,a,b,c,d,n;
	n = rand()%19 + 20;
	for(j=1;j<=n;j++) {
		t = rand()%3 + 1;
		// t=1 for choosy,2 for normal,3 for desperate girls
		a = rand()%617 + 200; // attractiveness
		b = rand()%23 + 10; // maintenance cost
		c = rand()%111 + 20; // intelligence
		d = rand()%3 + 1; // selection criteria
		// d=1 for most attractive, d=2 for richest, d=3 for most intelligent

		//writing to file
		if(j<n)
			file1<<"GIRL"<<j<<" "<<t<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
		else
			file1<<"GIRL"<<j<<" "<<t<<" "<<a<<" "<<b<<" "<<c<<" "<<d;
	}
	file1.close();

	ofstream file2 ("boys.txt");
	n = rand()%59 + 30;
	for(j=1;j<=n;j++) {
		t = rand()%3 + 1;
		// t=1 for miser,2 for generous,3 for geek boys
		a = rand()%211 + 35; // attractiveness
		b = rand()%129 + 24; // intelligence
		c = rand()%59 + 35; // budget
		d = rand()%157 + 40; // minimum attraction requirement

		//writing to file
		if(j<n)
			file2<<"BOY"<<j<<" "<<t<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
		else
			file2<<"BOY"<<j<<" "<<t<<" "<<a<<" "<<b<<" "<<c<<" "<<d;

	}
	file2.close();

	ofstream file3 ("gifts.txt");
	n = rand()%149 + 100;
	for(j=1;j<=n;j++) {
		t = rand()%3 + 1;
		// t=1 for essential, 2 for luxury, 3 for utility
		a = rand()%5 + 2; // price of gift
		b = rand()%17 + 3; // value of gift
		c = rand()%5 + 1; // luxury rating or the utility value
		d = rand()%9 + 1; // difficulty to obtain or the utility class

		if(t==1) {
			if(j<n)
				file3<<"GIFT"<<j<<" "<<t<<" "<<a<<" "<<b<<"\n";
			else
				file3<<"GIFT"<<j<<" "<<t<<" "<<a<<" "<<b;
		}
		else {
			a = rand()%12 + 3;
			b = rand()%35 + 9;
			if(j<n)
				file3<<"GIFT"<<j<<" "<<t<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
			else
				file3<<"GIFT"<<j<<" "<<t<<" "<<a<<" "<<b<<" "<<c<<" "<<d;
		}
	}
	file3.close();
	return ;
}


int give_gifts(int b_type, int g_type, string b_name, string g_name, Essential_gift gt1[250],
							Luxury_gift gt2[250], Utility_gift gt3[250],
							Couple c[50], int maintenance, int budget, int c_cnt,
							int cnt_gt1, int cnt_gt2, int cnt_gt3, int intel)
{
	ofstream file5;
	file5.open("log.txt",ios::app);
	file5<<b_name<<" giving gifts to "<<g_name<<"\n";
	cout<<b_name<<" giving gifts to "<<g_name<<"\n";
	int total_price=0, total_value = 0;
	long double b_happy,g_happy;
	int sum = rand()%49 + 15,lux=0;
	if(b_type==2) {
		int upper_lim = budget;
		int i,given1[250],given2[250],given3[250];
		for(i=0;i<250;i++) {
			given1[i] = 0;
			given2[i] = 0;
			given3[i] = 0;
		}
		while(1) {
			int min1=1000,min2=1000,min3=1000,mini1,mini2,mini3;
			for(i=0;i<cnt_gt1;i++) {
				if(min1>gt1[i].price && (!given1[i])) {
					min1 = gt1[i].price;
					mini1=i;
				}
			}
			for(i=0;i<cnt_gt2;i++) {
				if(min2>gt2[i].price && (!given2[i])) {
					min2 = gt2[i].price;
					mini2=i;
				}
			}
			for(i=0;i<cnt_gt3;i++) {
				if(min3>gt3[i].price && (!given3[i])) {
					min3 = gt3[i].price;
					mini3=i;
				}
			}
			int fl=1;
			if(min1<min2 && min1<min3) {
				if(total_price+min1 <= upper_lim) {
					total_price += min1;
					total_value += gt1[mini1].value;
					given1[mini1]=1;
					fl=0;
					cout<<gt1[mini1].name<<"\n";
					file5<<gt1[mini1].name<<"\n";
				}
				else if(maintenance>total_price) {
					total_price += min1;
					total_value += gt1[mini1].value;
					given1[mini1]=1;
					cout<<gt1[mini1].name<<"\n";
					file5<<gt1[mini1].name<<"\n";
				}
			}
			else if(min2<min3) {
				if(total_price+min2 <= upper_lim) {
					total_price += min2;
					total_value += (2*(gt1[mini1].value));
					fl=0;
					given2[mini2]=1;
					cout<<gt2[mini2].name<<"\n";
					file5<<gt2[mini2].name<<"\n";	
				}
				else if(maintenance>total_price) {
					total_price += min2;
					total_value += gt2[mini2].value;
					given2[mini2]=1;
					cout<<gt2[mini2].name<<"\n";
					file5<<gt2[mini2].name<<"\n";
				}
				lux += (2*gt2[mini2].value);
			}
			else {
				if(total_price+min3 <= upper_lim) {
					total_price += min3;
					total_value += gt3[mini3].value;
					fl=0;
					given3[mini3]=1;
					cout<<gt3[mini3].name<<"\n";
					file5<<gt3[mini3].name<<"\n";
				}
				else if(maintenance>total_price) {
					total_price += min3;
					total_value += gt3[mini3].value;
					given3[mini3]=1;
					cout<<gt3[mini3].name<<"\n";
					file5<<gt3[mini3].name<<"\n";
				}
			}
			if(fl)
				break;
		}

	}
	
	else if(b_type==1) {
		int upper_lim = maintenance;
		int i,given1[250],given2[250],given3[250];
		for(i=0;i<250;i++) {
			given1[i] = 0;
			given2[i] = 0;
			given3[i] = 0;
		}
		while(1) {
			int min1=1000,min2=1000,min3=1000,mini1,mini2,mini3;
			for(i=0;i<cnt_gt1;i++) {
				if(min1>gt1[i].price && (!given1[i])) {
					min1 = gt1[i].price;
					mini1=i;
				}
			}
			for(i=0;i<cnt_gt2;i++) {
				if(min2>gt2[i].price && (!given2[i])) {
					min2 = gt2[i].price;
					mini2=i;
				}
			}
			for(i=0;i<cnt_gt3;i++) {
				if(min3>gt3[i].price && (!given3[i])) {
					min3 = gt3[i].price;
					mini3=i;
				}
			}
			int fl=1;
			if(min1<min2 && min1<min3) {
				if(total_price+min1 <= upper_lim) {
					total_price += min1;
					total_value += gt1[mini1].value;
					given1[mini1]=1;
					cout<<gt1[mini1].name<<"\n";
					file5<<gt1[mini1].name<<"\n";
					if(total_price!=upper_lim)
						fl=0;
				}
				else if(maintenance>total_price) {
					total_price += min1;
					total_value += gt1[mini1].value;
					given1[mini1]=1;
					cout<<gt1[mini1].name<<"\n";
					file5<<gt1[mini1].name<<"\n";
				}
			}
			else if(min2<min3) {
				if(total_price+min2 <= upper_lim) {
					total_price += min2;
					total_value += (2*(gt1[mini1].value));
					if(total_price!=upper_lim)
						fl=0;
					given2[mini2]=1;
					cout<<gt2[mini2].name<<"\n";
					file5<<gt2[mini2].name<<"\n";
				}
				else if(maintenance>total_price) {
					total_price += min2;
					total_value += gt2[mini2].value;
					given2[mini2]=1;
					cout<<gt2[mini2].name<<"\n";
					file5<<gt2[mini2].name<<"\n";
				}
				lux += (2*gt2[mini2].value);
			}
			else {
				if(total_price+min3 <= upper_lim) {
					total_price += min3;
					total_value += gt3[mini3].value;
					if(total_price!=upper_lim)
						fl=0;
					given3[mini3]=1;
					cout<<gt3[mini3].name<<"\n";
					file5<<gt3[mini3].name<<"\n";
				}
				else if(maintenance>total_price) {
					total_price += min3;
					total_value += gt3[mini3].value;
					given3[mini3]=1;
					cout<<gt3[mini3].name<<"\n";
					file5<<gt3[mini3].name<<"\n";
				}
			}
			if(fl)
				break;
		}
	}
	
	else {
		int upper_lim = maintenance;
		int i,given1[250],given2[250],given3[250];
		for(i=0;i<250;i++) {
			given1[i] = 0;
			given2[i] = 0;
			given3[i] = 0;
		}
		while(1) {
			int min1=1000,min2=1000,min3=1000,mini1,mini2,mini3;
			for(i=0;i<cnt_gt1;i++) {
				if(min1>gt1[i].price && (!given1[i])) {
					min1 = gt1[i].price;
					mini1=i;
				}
			}
			for(i=0;i<cnt_gt2;i++) {
				if(min2>gt2[i].price && (!given2[i])) {
					min2 = gt2[i].price;
					mini2=i;
				}
			}
			for(i=0;i<cnt_gt3;i++) {
				if(min3>gt3[i].price && (!given3[i])) {
					min3 = gt3[i].price;
					mini3=i;
				}
			}
			int fl=1;
			if(min1<min2 && min1<min3) {
				if(total_price+min1 <= upper_lim) {
					total_price += min1;
					total_value += gt1[mini1].value;
					given1[mini1]=1;
					cout<<gt1[mini1].name<<"\n";
					file5<<gt1[mini1].name<<"\n";
					if(total_price!=upper_lim)
						fl=0;
				}
				else if(maintenance>total_price) {
					total_price += min1;
					total_value += gt1[mini1].value;
					given1[mini1]=1;
					cout<<gt1[mini1].name<<"\n";
					file5<<gt1[mini1].name<<"\n";
				}
			}
			else if(min2<min3) {
				if(total_price+min2 <= upper_lim) {
					total_price += min2;
					total_value += (2*(gt2[mini2].value));
					if(total_price!=upper_lim)
						fl=0;
					given2[mini2]=1;
					cout<<gt2[mini2].name<<"\n";
					file5<<gt2[mini2].name<<"\n";
				}
				else if(maintenance>total_price) {
					total_price += min2;
					total_value += gt2[mini2].value;
					given2[mini2]=1;
					cout<<gt2[mini2].name<<"\n";
					file5<<gt2[mini2].name<<"\n";
				}
				lux += (2*gt2[mini2].value);
			}
			else {
				if(total_price+min3 <= upper_lim) {
					total_price += min3;
					total_value += gt3[mini3].value;
					if(total_price!=upper_lim)
						fl=0;
					given3[mini3]=1;
					cout<<gt3[mini3].name<<"\n";
					file5<<gt3[mini3].name<<"\n";
				}
				else if(maintenance>total_price) {
					total_price += min3;
					total_value += gt3[mini3].value;
					given3[mini3]=1;
					cout<<gt3[mini3].name<<"\n";
					file5<<gt3[mini3].name<<"\n";
				}
			}
			if(fl)
				break;
		}
		int m2=1000,mi2;
		for(i=0;i<cnt_gt2;i++) {
				if(m2>gt2[i].price && (!given2[i])) {
					m2 = gt2[i].price;
					mi2=i;
				}
		}
		if(total_price + m2 <= budget) {
			total_price += m2;
			total_value += (2*(gt2[mi2].value));
			cout<<gt2[mi2].name<<"\n";
			file5<<gt2[mi2].name<<"\n";
		}

	}
	file5<<"\n\n\n";
	cout<<"\n\n\n";
	int luxury_value = sum;
	if(g_type==1)
		g_happy = log(total_price - maintenance + 2*lux);
	else if(g_type == 2)
		g_happy = total_value + total_price;
	else
		g_happy = exp(total_price);
	if(b_type==1)
		b_happy = budget -total_price;
	else if(b_type==2)
		b_happy = g_happy;
	else
		b_happy = intel;
	c[c_cnt].boy_name = b_name;
	c[c_cnt].girl_name = g_name;
	c[c_cnt].couple_happiness = b_happy + g_happy;
	c[c_cnt].gift_total_price = total_price;
	return total_price;
}


void read_pairup_and_gift(Choosy_girl g1[50],
							Normal_girl g2[50],
							Desperate_girl g3[50],
							Miser_boy b1[100],
							Generous_boy b2[100],
							Geek_boy b3[100],
							Essential_gift gt1[250],
							Luxury_gift gt2[250],
							Utility_gift gt3[250],
							Couple c1[50],
							int *couple_count)
{
	fstream file1 ("girls.txt");
	fstream file2 ("boys.txt");
	int cnt_b1=0,cnt_b2=0,cnt_b3=0;
	string name;
	int t,a,b,c,d;
	while(!file2.eof()) {
		file2>>name>>t>>a>>b>>c>>d;
		//cout<<name<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
		if(t==1) {
			b1[cnt_b1].name = name;
			b1[cnt_b1].attractiveness = a;
			b1[cnt_b1].intelligence = b;
			b1[cnt_b1].budget = c;
			b1[cnt_b1].min_attraction_of_girl = d;
			cnt_b1++;
		}
		else if(t==2) {
			b2[cnt_b2].name = name;
			b2[cnt_b2].attractiveness = a;
			b2[cnt_b2].intelligence = b;
			b2[cnt_b2].budget = c;
			b2[cnt_b2].min_attraction_of_girl = d;
			cnt_b2++;
		}
		else {
			b3[cnt_b3].name = name;
			b3[cnt_b3].attractiveness = a;
			b3[cnt_b3].intelligence = b;
			b3[cnt_b3].budget = c;
			b3[cnt_b3].min_attraction_of_girl = d;
			cnt_b3++;
		}
	}

	fstream file3 ("gifts.txt");
	int cnt_gt1=0,cnt_gt2=0,cnt_gt3=0;
	while(!file3.eof()) {
		file3>>name>>t>>a>>b;
		if(t==1) {
			gt1[cnt_gt1].name = name;
			gt1[cnt_gt1].price = a;
			gt1[cnt_gt1].value = b;
			cnt_gt1++;
		}
		else if(t==2) {
			file3>>c>>d;
			gt2[cnt_gt2].name = name;
			gt2[cnt_gt2].price = a;
			gt2[cnt_gt2].value = b;
			gt2[cnt_gt2].luxury_rating = c;
			gt2[cnt_gt2].difficulty = d;
			cnt_gt2++;
		}
		else {
			file3>>c>>d;
			gt3[cnt_gt3].name = name;
			gt3[cnt_gt3].price = a;
			gt3[cnt_gt3].value = b;
			gt3[cnt_gt3].utility_value = c;
			gt3[cnt_gt3].utility_class = d;
			cnt_gt3++;
		}
	}
	remove("log.txt");
	int cnt_g1=0,cnt_g2=0,cnt_g3=0,c_cnt=0,attr,inte,m1,m2,m3;
	while(!file1.eof()) {
		file1>>name>>t>>a>>b>>c>>d;
		int b_type,g_type=d,intel=c,maintain=b,buget;
		string b_name,g_name;
		g_name=name;
		if(t==1) {
			g1[cnt_g1].name = name;
			g1[cnt_g1].attractiveness = a;
			g1[cnt_g1].maintenance = b;
			g1[cnt_g1].intelligence = c;
			g1[cnt_g1].selection_criteria = d;
			cnt_g1++;
		}
		else if(t==2) {
			g2[cnt_g2].name = name;
			g2[cnt_g2].attractiveness = a;
			g2[cnt_g2].maintenance = b;
			g2[cnt_g2].intelligence = c;
			g2[cnt_g2].selection_criteria = d;
			cnt_b2++;
		}
		else {
			g3[cnt_g3].name = name;
			g3[cnt_g3].attractiveness = a;
			g3[cnt_g3].maintenance = b;
			g3[cnt_g3].intelligence = c;
			g3[cnt_g3].selection_criteria = d;
			cnt_g3++;
		}
		//girl wants most attractive guy
		if(d==1) {
			int i,maxi1=-1,maxi2=-1,maxi3=-1,max1,max2,max3,checked[100];
			max1=max2=max3=-100;
			for(i=0;i<100;i++)
				checked[i] = 0;
			while(1) {
				maxi1=-100;
				max1=-1;
				bool flag=true;
				for(i=0;i<cnt_b1;i++) {
					if(checked[i]==0 && !(b1[i].is_committed)) {
						if(b1[i].attractiveness > max1) {
							max1 = b1[i].attractiveness;
							maxi1 = i;
						}
						flag=false;
					}
				}
				if(flag)
					break;
				if(b1[maxi1].budget >= b &&
					b1[maxi1].min_attraction_of_girl <= a) {
					break;
				}
				else {
					checked[maxi1]=1;
				}
			}
			for(i=0;i<100;i++)
				checked[i] = 0;
			while(1) {
				maxi2=-100;
				max2=-1;
				bool flag=true;
				for(i=0;i<cnt_b2;i++) {
					if(checked[i]==0 && !(b2[i].is_committed)) {
						if(b2[i].attractiveness > max2) {
							max2 = b2[i].attractiveness;
							maxi2 = i;
						}
						flag=false;
					}
				}
				if(flag)
					break;
				if(b2[maxi2].budget >= b &&
					b2[maxi2].min_attraction_of_girl <= a) {
					break;
				}
				else {
					checked[maxi2]=1;
				}
			}
			for(i=0;i<100;i++)
				checked[i] = 0;
			while(1) {
				maxi3=-100;
				max3=-1;
				bool flag=true;
				for(i=0;i<cnt_b3;i++) {
					if(checked[i]==0 && !(b3[i].is_committed)) {
						if(b3[i].attractiveness > max3) {
							max3 = b3[i].attractiveness;
							maxi3 = i;
						}
						flag=false;
					}
				}
				if(flag)
					break;
				if(b3[maxi3].budget >= b &&
					b3[maxi3].min_attraction_of_girl <= a) {
					break;
				}
				else {
					checked[maxi3]=1;
				}
			}
			//no eligible boyfriend possible
			if(max1==max2&&max2==max3&&max3==-1)
				continue;
			if(t==1)
				g1[cnt_g1-1].is_committed=true;
			else if(t==2)
				g2[cnt_g2-1].is_committed=true;
			else
				g3[cnt_g3-1].is_committed=true;
					
			//choosing the best out of 3 categories of boys
			if(max1>max2&&max1>max3) {
				b1[maxi1].is_committed=true;
				b_name=b1[maxi1].name;
				buget = b1[maxi1].budget;
				b_type=1;
				attr = b1[maxi1].attractiveness;
				inte = b1[maxi1].intelligence;
				m1 = maxi1;
			}
			else if(max2>max3) {
				b2[maxi2].is_committed=true;
				b_name=b2[maxi2].name;
				buget = b2[maxi2].budget;
				b_type=2;
				attr = b2[maxi2].attractiveness;
				inte = b2[maxi2].intelligence;
				m2 = maxi2;
			}
			else {
				b3[maxi3].is_committed=true;
				b_name=b3[maxi3].name;
				buget = b3[maxi3].budget;
				b_type=3;
				m3 = maxi3;
			}
		}
		//girl wants richest guy
		else if(d==2) {
			int i,maxi1=-1,maxi2=-1,maxi3=-1,max1,max2,max3,checked[100];
			max1=max2=max3=-100;
			for(i=0;i<100;i++)
				checked[i] = 0;
			while(1) {
				maxi1=-100;
				max1=-1;
				bool flag=true;
				for(i=0;i<cnt_b1;i++) {
					if(checked[i]==0 && !(b1[i].is_committed)) {
						if(b1[i].budget > max1) {
							max1 = b1[i].budget;
							maxi1 = i;
						}
						flag=false;
					}
				}
				if(flag)
					break;
				if(b1[maxi1].budget >= b &&
					b1[maxi1].min_attraction_of_girl <= a) {
					break;
				}
				else {
					checked[maxi1]=1;
				}
			}
			for(i=0;i<100;i++)
				checked[i] = 0;
			while(1) {
				maxi2=-100;
				max2=-1;
				bool flag=true;
				for(i=0;i<cnt_b2;i++) {
					if(checked[i]==0 && !(b2[i].is_committed)) {
						if(b2[i].budget > max2) {
							max2 = b2[i].budget;
							maxi2 = i;
						}
						flag=false;
					}
				}
				if(flag)
					break;
				if(b2[maxi2].budget >= b &&
					b2[maxi2].min_attraction_of_girl <= a) {
					break;
				}
				else {
					checked[maxi2]=1;
				}
			}
			for(i=0;i<100;i++)
				checked[i] = 0;
			while(1) {
				maxi3=-100;
				max3=-1;
				bool flag=true;
				for(i=0;i<cnt_b3;i++) {
					if(checked[i]==0 && !(b3[i].is_committed)) {
						if(b3[i].budget > max3) {
							max3 = b3[i].budget;
							maxi3 = i;
						}
						flag=false;
					}
				}
				if(flag)
					break;
				if(b3[maxi3].budget >= b &&
					b3[maxi3].min_attraction_of_girl <= a) {
					break;
				}
				else {
					checked[maxi3]=1;
				}
			}
			//no eligible boyfriend possible
			if(max1==max2&&max2==max3&&max3==-1)
				continue;
			if(t==1)
				g1[cnt_g1-1].is_committed=true;
			else if(t==2)
				g2[cnt_g2-1].is_committed=true;
			else
				g3[cnt_g3-1].is_committed=true;
					
			//choosing the best out of 3 categories of boys
			if(max1>max2&&max1>max3) {
				b1[maxi1].is_committed=true;
				b_name=b1[maxi1].name;
				buget = b1[maxi1].budget;
				b_type=1;
				attr = b1[maxi1].attractiveness;
				inte = b1[maxi1].intelligence;
				m1=max1;
			}
			else if(max2>max3) {
				b2[maxi2].is_committed=true;
				b_name=b2[maxi2].name;
				buget = b2[maxi2].budget;
				b_type=2;
				attr = b2[maxi2].attractiveness;
				inte = b2[maxi2].intelligence;
				m2=max2;
			}
			else {
				b3[maxi3].is_committed=true;
				b_name=b3[maxi3].name;
				buget = b3[maxi3].budget;
				b_type=3;
				attr = b3[maxi3].attractiveness;
				inte = b3[maxi3].intelligence;
				m3=max3;
			}
		}
		else if(d==3) {
			int i,maxi1=-1,maxi2=-1,maxi3=-1,max1,max2,max3,checked[100];
			max1=max2=max3=-100;
			for(i=0;i<100;i++)
				checked[i] = 0;
			while(1) {
				maxi1=-100;
				max1=-1;
				bool flag=true;
				for(i=0;i<cnt_b1;i++) {
					if(checked[i]==0 && !(b1[i].is_committed)) {
						if(b1[i].attractiveness > max1) {
							max1 = b1[i].attractiveness;
							maxi1 = i;
						}
						flag=false;
					}
				}
				if(flag)
					break;
				if(b1[maxi1].budget >= b &&
					b1[maxi1].min_attraction_of_girl <= a) {
					break;
				}
				else {
					checked[maxi1]=1;
				}
			}
			for(i=0;i<100;i++)
				checked[i] = 0;
			while(1) {
				maxi2=-100;
				max2=-1;
				bool flag=true;
				for(i=0;i<cnt_b2;i++) {
					if(checked[i]==0 && !(b2[i].is_committed)) {
						if(b2[i].attractiveness > max2) {
							max2 = b2[i].attractiveness;
							maxi2 = i;
						}
						flag=false;
					}
				}
				if(flag)
					break;
				if(b2[maxi2].budget >= b &&
					b2[maxi2].min_attraction_of_girl <= a) {
					break;
				}
				else {
					checked[maxi2]=1;
				}
			}
			for(i=0;i<100;i++)
				checked[i] = 0;
			while(1) {
				maxi3=-100;
				max3=-1;
				bool flag=true;
				for(i=0;i<cnt_b3;i++) {
					if(checked[i]==0 && !(b3[i].is_committed)) {
						if(b3[i].attractiveness > max3) {
							max3 = b3[i].attractiveness;
							maxi3 = i;
						}
						flag=false;
					}
				}
				if(flag)
					break;
				if(b3[maxi3].budget >= b &&
					b3[maxi3].min_attraction_of_girl <= a) {
					break;
				}
				else {
					checked[maxi3]=1;
				}
			}
			//no eligible boyfriend possible
			if(max1==max2&&max2==max3&&max3==-1)
				continue;
			if(t==1)
				g1[cnt_g1-1].is_committed=true;
			else if(t==2)
				g2[cnt_g2-1].is_committed=true;
			else
				g3[cnt_g3-1].is_committed=true;
					
			//choosing the best out of 3 categories of boys
			if(max1>max2&&max1>max3) {
				b1[maxi1].is_committed=true;
				b_name=b1[maxi1].name;
				buget = b1[maxi1].budget;
				b_type=1;
				attr = b1[maxi1].attractiveness;
				inte = b1[maxi1].intelligence;
				m1 = maxi1;
			}
			else if(max2>max3) {
				b2[maxi2].is_committed=true;
				b_name=b2[maxi2].name;
				buget = b2[maxi2].budget;
				b_type=2;
				attr = b2[maxi2].attractiveness;
				inte = b2[maxi2].intelligence;
				m2 = maxi2;
			}
			else {
				b3[maxi3].is_committed=true;
				b_name=b3[maxi3].name;
				buget = b3[maxi3].budget;
				b_type=3;
				attr = b3[maxi3].attractiveness;
				inte = b3[maxi3].intelligence;
				m3 = maxi3;
			}
		}
		ofstream file4("log.txt",ios::app);
		file4<<"Committment : "<<g_name<<"          "<<b_name<<"\n";
		file4.close();
		int cc = give_gifts(b_type,g_type,b_name,g_name,gt1,gt2,gt3,c1,maintain,buget,c_cnt,cnt_gt1,cnt_gt2,cnt_gt3,intel);
		c1[c_cnt].couple_compatibility = (abs(buget - b) + abs(attr-a) + abs(inte-intel));
		c_cnt++;
		if(b_type==1) {
			if(b1[m1].budget < cc)
				b1[m1].budget = cc;
		}
		else if(b_type==2) {
			if(b2[m2].budget < cc)
				b2[m2].budget = cc;
		}
		else {
			if(b3[m3].budget < cc)
				b3[m3].budget = cc;
		}
	}
	*couple_count = c_cnt;
	
}
