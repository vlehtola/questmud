/* Distant heal */

resolve(bonus, string target) {
   object ob, ob2;
   string target2;
   int effect;
   if (!target) {
        ob = this_player();
   }
   if (!ob) ob = find_player(target);
   if (!ob || ob->query_link_dead()) {
        write("You are unable to locate "+capitalize(target)+".\n");
        return 1;
   }
   effect = "/guilds/spells/channel/_chl_hea_min"->get_heal_amount(bonus);
   effect = effect/2;
   ob->heal_hp(effect);

   target2 = target;
   target = capitalize(target);
   target2 = capitalize(target2);
   if(ob->query_wiz()) {
     write("Wizards do not require your aid.\n");
     return 1;
   }
   if (ob == this_player()) { target = "yourself"; target2 = "himself"; }
   write("You distantly heal " + target + ".\n");
   if (ob != this_player()) {
     tell_object(ob, capitalize(this_player()->query_name()) +
        " heals your wounds from a distance.\n");
   }

   return 1;
}
