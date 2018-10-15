#include <iostream>

using namespace std;

int main()
{
	//100x100 -> 999x999
	const int fn_min=101;
	const int sn_min=101;
	const int fn_max=999;
	const int sn_max=999;
	int prod_tmp=0;
	int PAL_max=0;

	for (int i=0;i<fn_max-fn_min+1; ++i)
		{
		for (int k=0; k<sn_max-sn_min+1; ++k)
			{
				int fn=fn_min+i;
				int sn=sn_min+k;
				int mod_f = fn%10;
				int mod_s = sn%10;
			if (mod_f !=0 && mod_s !=0 && (mod_f*mod_s)%10!=0)
				{
					prod_tmp=(fn)*(sn);

					//checking 5-digit numbers
					//-----------------------
				if(prod_tmp<99999\
				   && prod_tmp/10000==prod_tmp%10 \
				   && (prod_tmp%10000)/1000==(prod_tmp/10)%10)
					{
						cout<< "fn= "<< (fn) <<"; sn= "<<(sn)<<\
							   "; prod_tmp= "<< prod_tmp<<"; mod_f= "\
							<< mod_f <<"; mod_s= "<< mod_s <<endl;

						if (prod_tmp>PAL_max) {PAL_max=prod_tmp;}
					}

				//checking 6-digit numbers
				//-----------------------
				else if (prod_tmp<999999\
						 && prod_tmp/100000==prod_tmp%10 \
						 && (prod_tmp%100000)/10000==(prod_tmp/10)%10   \
						 && (prod_tmp%10000)/1000==(prod_tmp/100)%10)
					{
					cout<< "fn= "<< (fn) <<"; sn= "<<(sn)<<"; prod_tmp= "<<\
						   prod_tmp<<"; mod_f= "<< mod_f<<"; mod_s= "\
						<< mod_s <<endl;

					if (prod_tmp>PAL_max) {PAL_max=prod_tmp;}
					}

				}
					else continue;
				}
		}


	cout << "\nPAL_max= " << PAL_max << endl;
	return 0;


}
