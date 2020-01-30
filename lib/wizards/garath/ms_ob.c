object p;
void start(object ob) {
  shadow(ob,1);
  p = ob;
}


hit_with_spell(int dmg,string pref, arg1,arg2,arg3) {
  p->set_sp( (p->query_sp()-dmg));
  if(p->query_sp() <= 0) {
    p->set_sp(0);
    tell_object(p,"The shield fades away.\n");
    destruct(this_object());
  }
}
