
reset(arg) {
  if(arg) return;
  tee_se();
}

string* quicksort(string *arr, int l, int r);
alpha_value(string str);

status tee_se() {
 string *str;
 int i;

 str=allocate(6);
 str=({"alpha","gamma","beta","celcius","hanibani","hurrpurr"}); 

 for(i=0;i<sizeof(str);i++)     {
 write(str[i][0..0]+" - ");

                                }
 write("\n");
str=quicksort(str, 0, sizeof(str));
   
 for(i=0;i<sizeof(str);i++)     {
 write(str[i][0..0]+" - ");

                                }

  return 1;
}

/****************/

string* quicksort(string *arr, int l, int r) {
int v,i,j;
string t;

write("QSort fun.");

if(r>l) {
v=alpha_value(arr[r-1][0..0]);
i=l-1; j=r;

while(1)
  { 
    while(alpha_value(arr[++i][0..0]) < v) {}
    while(alpha_value(arr[--j][0..0]) > v) {}
    if(i>=j) break;
    t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;
  }
  t=arr[i]; arr[i]=arr[r]; arr[r]=t;
  quicksort(arr, l, i-1);
  quicksort(arr, i+1, r);
 }

return arr;
}

/***************/

alpha_value(string str) {
 int i;
 string tmp;
 if(!str) return 0;
  tmp = lower_case(str);
  if(tmp == "a") i += 1;
  if(tmp == "b") i += 2;
  if(tmp == "c") i += 3;
  if(tmp == "d") i += 4;
  if(tmp == "e") i += 5;
  if(tmp == "f") i += 6;
  if(tmp == "g") i += 7;
  if(tmp == "h") i += 8;
  if(tmp == "i") i += 9;
  if(tmp == "j") i += 10;
  if(tmp == "k") i += 11;
  if(tmp == "l") i += 12;
  if(tmp == "m") i += 13;
  if(tmp == "n") i += 14;
  if(tmp == "o") i += 15;
  if(tmp == "p") i += 16;
  if(tmp == "q") i += 17;
  if(tmp == "r") i += 18;
  if(tmp == "s") i += 19;
  if(tmp == "t") i += 20;
  if(tmp == "u") i += 21;
  if(tmp == "v") i += 22;
  if(tmp == "w") i += 23;
  if(tmp == "x") i += 24;
  if(tmp == "y") i += 25;
  if(tmp == "z") i += 26;
 return i;
}

