
reset(arg) {
  if(arg) return;
  tee_se();
}

status tee_se() {
 string *str;
 int i;

 str=allocate(6);
 str=({"alpha","gamma","beta","celcius","hanibani","hurrpurr"}); 

 for(i=0;i<sizeof(str);i++)     {
 write(str[i][0..0]+" - ");

                                }
 write("\n");

   

  return 1;
}

/****************/

quicksort(string *arr, int l, int r) {
int i;
for(i=0;i<sizeof(arr);i++)      {
 write(arr[i][0..0]+" - ");

                                }
write("\n");
}
