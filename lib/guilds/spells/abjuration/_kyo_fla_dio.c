#define MASTERY_D "/daemons/mastery_d"

resolve(int bonus, string target) {
        object ob,haste_ob;
        int i;
        string target2,desc;
        i = this_player()->query_skills("shielding mastery")+this_player()->query_wis();
        if(!target) { write("Cast at what?\n"); return 1; }
        ob = present(target, environment(this_player()));
        if(!ob) {
                 write("Cast at what?.\n");
                return 1;
                }
                if(!living(ob)) { write("This spell works only living targets.\n");
                return 1;
        }
        target2 = capitalize(target);
        target = capitalize(target);
        desc = target+" is already hasted.\n";
        if(ob == this_player()) {
                        target = "yourself";
            target2 = this_player()->query_objective()+"self";
            desc = "You are already hasted.\n";
                }

        if(ob->query_haste()) { write(desc); return 1; }
        if(ob->query_npc()) { write("This spell works only players.\n"); return 1; }

   i += MASTERY_D->mastery("Knowledge of shielding",this_player(),ob)*3/2;

   write("You cast haste at "+target+".\n");
   say(this_player()->query_name()+" casts haste at "+target2+".\n",ob);
   if(ob != this_player()) {
           tell_object(ob, this_player()->query_name()+" casts a haste at you.\n");
   }

   haste_ob = clone_object("/guilds/spell_obj/haste_ob");
   haste_ob->start(ob,i);
   return 1;
}
