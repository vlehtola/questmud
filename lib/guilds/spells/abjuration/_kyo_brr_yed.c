#define MASTERY_D "/daemons/mastery_d"

resolve(int bonus, string target) {
        object ob,anticounter;
        int i;
        string target2,desc;
        i = this_player()->query_skills("shielding mastery")+this_player()->query_wis();
        if(!target) { write("Cast at what?\n"); return 1; }
        ob = present(target, environment(this_player()));
        if(!ob) {
               write("No "+capitalize(target)+" here.\n");
               return 1;
                }
                if(!living(ob)) { write("This spell can only be casted at living things.\n");
                return 1;
        }
       target2 = capitalize(target);
       target = capitalize(target);
       desc = target+" has already an anti counter.\n";
        if(ob == this_player()) {
                target = "yourself";
                target2 = this_player()->query_objective()+"self";
                desc = "You already have an anti counter.\n";
        }

        if(ob->query_anticounter()) { write(desc); return 1; }

   i += MASTERY_D->mastery("Knowledge of shielding",this_player(),ob)*3/2;

   write("You cast anti counter at "+target+".\n");
   say(this_player()->query_name()+" casts anti counter at "+target2+".\n",ob);
   if(ob != this_player()) {
           tell_object(ob, this_player()->query_name()+" casts an anti counter upon you.\n");
   }
   anticounter = clone_object("/guilds/spell_obj/anticounter");
   anticounter->start(ob,i);
   return 1;
}
