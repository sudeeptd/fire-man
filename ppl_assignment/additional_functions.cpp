#include "additional_functions.h"
#include <bits/stdc++.h>
using namespace std;



// Creating random file for girls
void generate_input()
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

	return ;
}

void read_input_and_pair(Choosy_girl g1[50],
						Normal_girl g2[50],
						Desperate_girl g3[50],
						Miser_boy b1[100],
						Generous_boy b2[100],
						Geek_boy b3[100],
						vector< pair<string, string> > *couples)
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
	int cnt_g1=0,cnt_g2=0,cnt_g3=0;

	while(!file1.eof()) {
		file1>>name>>t>>a>>b>>c>>d;
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
				(*couples).push_back(make_pair(name,b1[maxi1].name));
			}
			else if(max2>max3) {
				b2[maxi2].is_committed=true;
				(*couples).push_back(make_pair(name,b2[maxi2].name));
			}
			else {
				b3[maxi3].is_committed=true;
				(*couples).push_back(make_pair(name,b3[maxi3].name));
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
				(*couples).push_back(make_pair(name,b1[maxi1].name));
			}
			else if(max2>max3) {
				b2[maxi2].is_committed=true;
				(*couples).push_back(make_pair(name,b2[maxi2].name));
			}
			else {
				b3[maxi3].is_committed=true;
				(*couples).push_back(make_pair(name,b3[maxi3].name));
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
				(*couples).push_back(make_pair(name,b1[maxi1].name));
			}
			else if(max2>max3) {
				b2[maxi2].is_committed=true;
				(*couples).push_back(make_pair(name,b2[maxi2].name));
			}
			else {
				b3[maxi3].is_committed=true;
				(*couples).push_back(make_pair(name,b3[maxi3].name));
			}
		}
	}
}

void print_couples(vector< pair<string, string> > couples)
{
	vector <pair <string, string> >::iterator it;
	ofstream file1("log.txt");
	cout<<"Couples\n"<<"Girl name       Boy name\n";

	for(it=couples.begin();it!=couples.end();it++) {
		cout<<it->first<<"          "<<it->second<<"\n";
		file1<<"Committment : "<<it->first<<"          "<<it->second<<"\n";
	}
	file1.close();
	

}


void print_k_happiest(Couple c[50], int cnt)
{
	int i,k = rand()%5 + 3;
	int visited[50];
	cout<<k<<" happiest couples are : \n";
	cout<<"Boy     Girl      Happiness\n";
	for(i=0;i<50;i++)
		visited[i]=0;
	while(k--) {
		long double mx=-1;
		int mxi;
		for(i=0;i<cnt;i++) {
			if(mx < c[i].couple_happiness  && visited[i]==0) {
				mx = c[i].couple_happiness;
				mxi = i;
			}
		}
		visited[mxi]=1;
		cout<<c[mxi].boy_name<<"   "<<c[mxi].girl_name<<"   "<<c[mxi].couple_happiness<<"\n";
	}
	printf("\n\n\n");

}

void print_k_most_compatible(Couple c[50], int cnt)
{
	int i,k = rand()%5 + 3;
	int visited[50];
	cout<<k<<" most compatible couples are : \n";
	cout<<"Boy     Girl     Compatibility\n";
	for(i=0;i<50;i++)
		visited[i]=0;
	while(k--) {
		int mx=-1;
		int mxi;
		for(i=0;i<cnt;i++) {
			if(mx < c[i].couple_compatibility  && visited[i]==0) {
				mx = c[i].couple_compatibility;
				mxi = i;
			}
		}
		visited[mxi]=1;
		cout<<c[mxi].boy_name<<"   "<<c[mxi].girl_name<<"   "<<c[mxi].couple_compatibility<<"\n";
	}
	
}
