cmd_resists(string arg) {
  object tp;
  if(arg && this_player()->query_wiz())
    tp = find_player(arg);
  if(!tp) tp = this_player();
  write("Fire:     " + adjektiivit(tp->query_resists("fire"))+" \n");
  write("Cold:     " + adjektiivit(tp->query_resists("cold"))+ " \n");
  write("Physical: " + adjektiivit(tp->query_resists("physical"))+ " \n");
  write("Electric: " + adjektiivit(tp->query_resists("electric"))+ " \n");
  write("Poison:   " + adjektiivit(tp->query_resists("poison"))+ " \n");
  write("Psionic:  " + adjektiivit(tp->query_resists("psionic"))+ " \n");
  write("Acid:     " + adjektiivit(tp->query_resists("acid"))+ " \n");
return 1;
}

adjektiivit(i) {
  int wizs;
  wizs = this_player()->query_wiz();
    if (!wizs) {
    return call_other("/guilds/obj/skillpros", "pros_names", i);
}
return i;
 }
