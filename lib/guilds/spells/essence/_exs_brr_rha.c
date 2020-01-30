//Added maximum amount of items to prevent 'Too long evaluation'
//Rag
#define SKILL "mastery of commerce"
#define MAX 300

resolve(int bonus, target, caster_ob) {
  object ob;
  int cash,i,tmp;
  if(!caster_ob)caster_ob=this_player();
  ob = all_inventory(environment(caster_ob));
  if(sizeof(ob) > MAX) {
        tell_object(caster_ob,"The number of items is too much for your brain.\n");
        tell_room(environment(caster_ob),caster_ob->query_name()+" seems to be unable to handle the amount of the items.\n", ({caster_ob}));
        return 1;
  }
  while(i<sizeof(ob)) {
    tmp = ob[i]->query_value();
    if(tmp && !living(ob[i]) && !ob[i]->query_money() && (ob[i]->query_armour() || ob[i]->query_weapon())) {
      cash += tmp;
      destruct(ob[i]);
    }
    i += 1;
  }
  cash = cash * (100+caster_ob->query_skills(SKILL)) / 100;
  cash = cash / 5;
  if(!cash) {
    tell_object(caster_ob, "There are no valuable items on the ground.\n");
    tell_room(environment(caster_ob), caster_ob->query_name()+"'s spell seems ineffective.\n", ({ caster_ob }));
    return 1;
  }
  ob = clone_object("/obj/new_money");
  ob->add_value(cash);
  ob->set_type(3);
  move_object(ob,environment(caster_ob));
  tell_object(caster_ob, "As you invoke the magic words, all items around you possessing some\nvalue utterly turn into money.\n");
  tell_room(environment(caster_ob), caster_ob->query_name()+" transforms all items into money!\n");
  log_file("EQ_TO_CASH", ctime(time())+" "+this_player()->query_name()+" turned eq into gold for "+cash+" bronze coins.\n");
}
