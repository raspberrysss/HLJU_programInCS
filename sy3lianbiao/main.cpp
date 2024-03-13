#include <iostream>
#include"link00.h"

using namespace std;

int main(void)
{
    int n;
  Link l1;
  //Node *h;
  //h=l1.gethead();
  cin>>n;
  l1.creatlink(n);
  l1.output();
  cout<<endl;
  l1.insert_link(6);
  l1.output();
  cout<<endl;
  l1.delete_link(5);
  l1.output();
  cout<<endl;

    return 0;
}
