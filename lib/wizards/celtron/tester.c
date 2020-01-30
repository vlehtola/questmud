reduce_experience(int exp,string str) {
  int tmp,tmp2,i,mega;
  string temp,temp2;
  if(intp(str)) str = to_string(str);
  /* 100M >= */
  if(str && strlen(str) > 8) {
    /* 9 876 543 210 */
    temp = extract(str,strlen(str)-8, strlen(str));
    temp2 = extract(str,0,strlen(str)-9);
  } else if(str) {
    temp = extract(str,0,strlen(str));
  } else {
    tell_object(this_object(), "Error in reduce_total_worth\n");
    return 1;
  }
  if(temp) tmp = to_int(temp);
  if(temp2) tmp2 = to_int(temp2);
  mega = 100000000; /* 100 megaa */
  /* reduce 100M bulks */
  if(exp/mega) {
    tmp2 -= exp/mega;
    exp -= exp/mega*mega;
  }
  tmp -= exp;
  if(tmp < 0 && tmp2 > 0) {
    tmp2 -= 1;
    tmp += mega;
  }
  if(tmp<0 || tmp2 <0)
        log_file("REDUCE_EXPERIENCE", ctime(time())+" "+query_name()+" negative value\n");
  if(tmp <0) tmp = 0;
  if(tmp2<0) tmp2 = 0;
  temp = to_string(tmp);
  temp2 = to_string(tmp2);
  if(tmp2 != 0 && strlen(temp) < 8) {
    temp = extract("0000000000",0,7-strlen(temp)) + temp;
  }
  if(tmp2 == 0) temp2 = "";
  str = temp2+""+temp;
  return str;
}

