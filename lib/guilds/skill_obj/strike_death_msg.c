get_msg(ob) {
  string str;
  int i;
  i = this_player()->query_right_weapon()->query_type();
  if(i==1) {
    return ob->query_name()+" SCREAMS in agony as its head is SMASHED apart.\n";
  }
  if(i==2) {
    return ob->query_name()+"'s throat is CUT open and blood spills all over the ground!\n";
  }
  if(i==3) {
    return ob->query_name()+"'s whine ends, when "+ob->query_possessive()+" head is CRUELLY slashed off!\n";
  }
  return "";
}

