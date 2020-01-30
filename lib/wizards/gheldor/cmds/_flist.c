cmd_flist(string str) {
string funcs;
int i,tmp;

funcs = functionlist(this_player());
if(!str) {
  write("Usage: flist (first letters of the wanted function)\n");
  return 1;
}

write("Results:\n");
for(i=0;i<sizeof(funcs);i++) {
  if(funcs[i][0..strlen(str)-1] == str) write(funcs[i]+", ");
  tmp++;
}
write("\nTotal "+tmp+" results found.\n");
return 1;
}

