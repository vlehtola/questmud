/* puts the mapping arg in alphabetic order. returns indices allocate */
alpha(mapping arg) {
  mapping tmp, new_map;
  int i,ii,value,i_tmp;
  string str,new,tmp1,tmp2;
  if(!arg) arg = this_player()->query_skills();
  tmp = ([ ]);
  str = m_indices(arg);
  while(i < sizeof(str)) {
    i_tmp = get_value(str[i], 2);
    if(tmp[i_tmp]) {
      tmp[i_tmp] = tmp[i_tmp]+","+str[i];
    } else {
      tmp += ([ i_tmp : str[i] ]);
    }
    if(i_tmp > value) value = i_tmp;
    i += 1;
  }
  i = 0;
  new = allocate(sizeof(str));
  while(i<=value) {
    tmp1 = tmp[i];
    while (tmp1 && sscanf(tmp1, "%s,%s", tmp2,tmp1) ==2) {
      new[ii] = tmp2;
      ii+=1;
    }
    if(tmp1) {
      new[ii] = tmp1;
      ii += 1;
    }
    i += 1;
  }
  return new;
}


get_value(string str, int max_count) {
 int i,count,ii;
 string tmp;
 if(!str) return 0;
 while(count < max_count) {
  tmp = lower_case(str[count..count]);
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
  i = i * 30;
  count += 1;
 }
 return i;
}
