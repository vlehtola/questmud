resolve(bonus, string target) {
   object ob, ob2;
   string target2;
   int effect;
   if (!target) {
	ob = this_player();
   }
   if (!ob) ob = present(target, environment(this_player()));
   if (!ob) {
	write("No '"+capitalize(target)+"' here.\n");
	return 1;
   }
   effect = ob->query_max_hp() - ob->query_hp();

   ob->heal_hp(effect);

   target2 = target;
   if (stringp(target)) target = capitalize(target);
   if (stringp(target2)) target2 = capitalize(target2);
   if (ob == this_player()) {
     target = "yourself";
     target2 = this_player()->query_objective()+"self";
   }
   write("You cast True Heal at " + target + ".\n");
   say(capitalize(this_player()->query_name())+" cast True Heal at "+target2+".\n",ob);
   if (ob != this_player()) {
     tell_object(ob, capitalize(this_player()->query_name()) +
	" complete heals your wounds.\n");
   }

   return 1;
}
