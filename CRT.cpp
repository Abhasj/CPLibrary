for (int i = 0;i<num.size(); i++)
 			ans = (ans+rem[i]*(temp = m/num[i])*inverse(temp, num[i]))%m;
 		cout<<ans<<endl;