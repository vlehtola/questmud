get_text(dam,ob) {
  string name;
  name = ob->query_name();
  if(dam > 500)
    return name+" makes one lightning-fast move and delivers GREAT pain to you!\n";
  if(dam > 200)
    return name+" moves with blurring speed and hits you with an amazing force!\n";
  if(dam > 140)
    return name+" painfully hits you with an unbelievably fast move!\n";
  if(dam > 80)
    return "You grunt from pain that "+name+" delivers you.\n";
  if(dam > 50)
    return name+" quickly hits you with a strange move.\n";
  if(dam > 30)
    return name+" hits you with some nasty trick.\n";
  if(dam > 10)
    return name+" gives you a solid blow.\n";

  return name+" hits you with some pitiful moves.\n";
}
