get_text(dam,user) {
  string name;
 name = user->query_name();
  if(dam > 500)
    return name+" gives a strong bear hug and delivers GREAT pain to you!\n";
  if(dam > 200)
    return name+" runs towards you and tears you body with extremely force!\n";
  if(dam > 140)
    return name+" painfully claws you with an unbelievably fast move!\n";
  if(dam > 80)
    return "You grunt from pain as "+name+" tears you.\n";
  if(dam > 50)
    return name+" gives a powerful bite to your left leg.\n";
  if(dam > 30)
    return name+" hits you with sharp claws making your wounds start to bleed.\n";
  if(dam > 10)
    return name+" gives you a strong bear punch.\n";

  return name+" hits you with some pitiful slap.\n";
}

