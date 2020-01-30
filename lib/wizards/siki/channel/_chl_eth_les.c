/* Free reinc */

resolve(bonus, target, god,arg) {
   object ob,obje, r_ob;
   int effect, exp,i,i2,modifier, worth;
   string totals, tmp;

   if (!target) { write("Reincarnate whom?\n"); return; }
   ob = find_player(lower_case(target));
   if (!ob) { write("No such a player.\n"); return 1; }
   if (!ob->query_dead() && !arg) {
	write(capitalize(target) + " is not dead.\n");
	return 1;
   }
   if (ob->query_free_exp() != "0" && ob->query_free_exp() != 0) {
	write(capitalize(ob->query_real_name())+" has free experience, "+
		"can't be reincarnated.\n");
	return 1;
   }
   
  r_ob = clone_object("/guilds/spell_obj/reincobject");
  r_ob->start(ob, this_player()->query_name());
  write("Done casting. Now the target has been given a chance to choose your reincarnation if he wishes to do so.\n");
  return 1;
}


