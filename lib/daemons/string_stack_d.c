/* daemon to stack items short descs //Celtron */

string get_numeric_string(int i) {
  if(i<2) return 0;
  switch(i) {
  case 2: return "two times";
  case 3: return "three times";  
  case 4: return "four times";
  case 5: return "five times";
  case 6: return "six times";
  case 7: return "seven times";
  case 8: return "eight times";
  case 9: return "nine times";
  case 10: return "ten times";   
  }
  return "many times";
} 

string stack_item_list(string *list) {
  int i;
  mapping count;
  string stacked, numeric;
  
  count = ([ ]);
  for(i=0; i<sizeof(list); i++) { 
    // != 0 && != "" added by Rag 25.9.04
    if(list[i] != "" && list[i] != 0)
      count[list[i]] += 1;
  }
  list = m_indices(count);   
  for(i=0; i<sizeof(list); i++) {
    if(!stacked) stacked = "";
    else if(i+1 == sizeof(list)) stacked += " and ";
    else stacked += ", ";
    numeric = get_numeric_string(count[list[i]]);
    if(numeric) numeric += " ";
    else numeric = "";
    stacked += numeric + list[i];
  }
  return stacked;
} 

