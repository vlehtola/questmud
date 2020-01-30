#define MASTERY_D "/daemons/mastery_d"

resolve(int bonus, string target) {
        object ob,antireflect;
        int i;
        string target2,desc;
        i = this_player()->query_skills("shielding mastery")+this_player()->query_wis();
        if(!target) { write("Cast at what?\n"); return 1; }
        ob = present(target, environment(this_player()));
        if(!ob) {
                        write("No "+target+" here.\n");
                        return 1;
                }
                if(!living(ob)) { write("This spell can only be casted at living targets.\n");
                return 1;
        }
      target2 = capitalize(target);
          target = capitalize(target);
          desc = target+" has already an antireflect.\n";
          if(ob == this_player()) {
                target = "yourself";
                 target2 = this_player()->query_objective()+"self";
                  desc = "You already have an antireflect.\n";
         }

        if(ob->query_antireflect_bonus()) { write(desc); return 1; }

   i += MASTERY_D->mastery("Knowledge of shielding",this_player(),ob)*3/2;

   write("You cast a antireflecting shield at "+target+".\n");
   say(this_player()->query_name()+" casts an antireflecting shield at "+target2+".\n",ob);
  antireflect = clone_object("/guilds/spell_obj/antireflect");
  antireflect->start(ob,i);
   return 1;
}
