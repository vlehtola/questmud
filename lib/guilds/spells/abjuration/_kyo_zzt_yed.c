
resolve(int bonus, string target) {
        object ob,bane;
        int i;
        string target2,desc;
        i = this_player()->query_skills("shielding mastery")+this_player()->query_wis();
        if(!target) { write("Cast at what?\n"); return 1; }
        ob = present(target, environment(this_player()));
        if(!ob) {
                        write("There aren't such thing here.\n");
                        return 1;
                }
                if(!living(ob)) { write("This spell can only be casted at living targets.\n");
                return 1;
        }
        target2 = capitalize(target);
        target = capitalize(target);
        desc = target+" has already a magic bane.\n";
        if(ob == this_player()) {
			target = "yourself";
			target2 = this_player()->query_objective()+"self";
			desc = "You have already a magic bane.\n";
		}

        if(present("magic_bane", ob)) { write(desc); return 1; }
        write("You cast a magic bane at "+target+".\n");
        say(this_player()->query_name()+" casts a magic bane at "+target2+".\n",ob);
   tell_object(ob, "You feel like your magic powers are weakening.\n");
  bane = clone_object("/guilds/spell_obj/magic_bane");
  move_object(bane, ob);
  bane->start(ob,i);
  ob->attack_object(this_player());
   return 1;
}
