object mina;
int str,con,aika,per;

start(ob,percent) {
  int skill;
  mina = ob;
  per = percent;
  shadow(mina, 1);
  call_out("remove_bravery", random(600)+600);
}

query_bravery() {
  int value;
  value=mina->query_skills("bravery")*per/100;
  return value;
}

remove_bravery() { 
  tell_object(mina, "You feel less brave now.\n");
  destruct(this_object()); 
}
