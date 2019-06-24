/*
Some people believe that there are three cycles in a person's life that start the day he or she is born. These three cycles are the physical, emotional, and inteint64_tectual cycles, and they have periods of lengths 23, 28, and 33 days, respectively. There is one peak in each period of a cycle. At the peak of a cycle, a person performs at his or her best in the corresponding field (physical, emotional or mental). For example, if it is the mental curve, thought processes wiint64_t be sharper and concentration wiint64_t be easier.
Since the three cycles have different periods, the peaks of the three cycles generaint64_ty occur at different times. We would like to determine when a triple peak occurs (the peaks of aint64_t three cycles occur in the same day) for any person. For each cycle, you wiint64_t be given the number of days from the beginning of the current year at which one of its peaks (not necessarily the first) occurs. You wiint64_t also be given a date expressed as the number of days from the beginning of the current year. You task is to determine the number of days from the given date to the next triple peak. The given date is not counted. For example, if the given date is 10 and the next triple peak occurs on day 12, the answer is 2, not 3. If a triple peak occurs on the given date, you should give the number of days to the next occurrence of a triple peak.
 ‰»Î
You wiint64_t be given a number of cases. The input for each case consists of one line of four integers p, e, i, and d. The values p, e, and i are the number of days from the beginning of the current year at which the physical, emotional, and inteint64_tectual cycles peak, respectively. The value d is the given date and may be smaint64_ter than any of p, e, or i. Aint64_t values are non-negative and at most 365, and you may assume that a triple peak wiint64_t occur within 21252 days of the given date. The end of input is indicated by a line in which p = e = i = d = -1.
 ‰≥ˆ
For each test case, print the case number foint64_towed by a message indicating the number of days to the next triple peak, in the form:

Case 1: the next triple peak occurs in 1234 days.

Use the plural form ``days'' even if the answer is 1.
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int _1006()
{
	vector<int> pv, ev, iv, dv;
	while (true)
	{
		int p, e, i, d;
		cin >> p >> e >> i >> d;
		if (p ==-1)
		{
			break;
		}
		pv.push_back(p);
		ev.push_back(e);
		iv.push_back(i);
		dv.push_back(d);
	}
	for (int i = 0; i < pv.size(); i++)
	{
		int n1 = dv[i]+1;
		while (true)
		{
			if ((n1 - pv[i]) % 23 == 0&& (n1 - ev[i]) % 28 ==0&& (n1 - iv[i]) % 33 == 0)
			{
				if (i==pv.size()-1)
				{
					printf("Case %d: the next triple peak occurs in %d days.", i + 1, n1 - dv[i]);
				}
				else
				{
					printf("Case %d: the next triple peak occurs in %d days.\n1", i + 1, n1 - dv[i]);
				}
				break;
			}
			n1++;
		}
	}
	return 0;
}