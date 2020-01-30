init() {
        add_action("drink", "drink");
        add_action("pour", "pour");
}
pour(string str) {
  object ob;
  if (!this_player()->check_condis()) { return 1; }
  if(!str) {
  	write("Pour what?\n");
  	return 1;
  }
  ob = present(str,this_player());
  if(!ob) {
  	write("You don't have thing to pour.\n");
  	return 1;
  }
  if(!ob->query_potion()) {
  	write("Only vials can be poured on the ground.\n");
  	return 1;
  }
  if(!ob->query_full()) { write("That vial is empty.\n"); return 1; }
  if(ob->query_doze_left() == 0) { write("There nothing left to pour.\n"); return 1; }
  write("You pour the vial on the ground.\n");
  say(this_player()->query_name()+" pours the vial on the ground,\n");
  ob->do_pour();
  return 1;

}

drink(string str) {
object ob;
if (!this_player()->check_condis()) { return 1; }
if(!str) {
        write("Drink what?\n");
        return 1;
        }
ob = present(str,this_player());
if(!ob) {
        write("You don't have such thing to drink.\n");
        return 1;
}
if(!ob->query_potion()) {
        write("Only vials can be drinked.\n");
        return 1;
        }

if(!ob->query_full()) { write("That vial is empty.\n"); return 1; }
if(ob->query_prepared() == 0) { write("This vial is not prepared.\n"); return 1; }
if(ob->query_doze_left() == 0) { write("There nothing left to drink.\n"); return 1; }
if(call_other("/guilds/witch/obj/potion_d", "can_drink", ob->query_effect()) == 0) {
write("This vial can't be drinked.\n");
        return 1;
}
write("You drink the vial.\n");
say(this_player()->query_name()+" drinks vial.\n");
ob->get_effect();
return 1;
}
