#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    char t[2];
    int pos, i = 0, j = 0;
    while(i < a.length() && i < b.length()) {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
            t[0] = a[i];
            break;
        }
        i++;
    }
    i = i + 1;
    while (i < a.length() && i < b.length()) {
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') ||(a[i]>='0'&&a[i]<='9'))) {
            t[1] = a[i];
            break;
        }
        i++;
    }
    while (j < c.length() && j < d.length()) {
        if (c[j] == d[j] && isalpha(c[j])) {
            pos = j;
            break;
        }
        j++;
    }
    string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
    int m = isdigit(t[1]) ? t[1] - '0' : t[1] - 'A' + 10;//ascii confert to number
    cout << week[t[0]-'A'];
    printf("%02d:%02d", m, pos);
    return 0;
}
/*#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[4][60];
    int i;
    int flag1;
    for(i=0; i<4; i++)
    {
        cin.getline(str[i],strlen(str[i]));
    }
    int len;
    if(strlen(str[1])>strlen(str[2]))
    {
        len=strlen(str[1]);
    }
    else
    {
        len=strlen(str[2]);
    }
    for(j=0; j<len; j++)
    {
        if(str[1][j]==str[2][j])
        {
            flag1=1;
        }
    }

        return 0;
}*/
