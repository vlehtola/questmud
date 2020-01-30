
resolve(int bonus, string target) {
        object ob,fw;
	int success;
        if(!target) { write("Cast at what?\n"); return 1; }
        ob = present(target, this_player());
        if(!ob) {
                        write("You don't have such thing.\n");
                        return 1;
                }
                if(living(ob)) { write("This skill can only be casted at non living targets.\n");
                return 1;
        }
        if(function_exists("add_weight", ob)) { write(ob->short()+" weight cannot be reduced.\n"); return 1; }

 // add_feather_weight_count
   success = ob->add_feather_weight_count();
   if(this_player()->query_wiz()) {
	write("Success: "+ success+"\n");
  }
   if(this_player()->query_skills("mastery of protection") > random(110)) {
     write("The spell's effect is stronger as you succeed in totally mastering it.\n");
     ob->add_feather_weight_count();
   }
   if(success) {
     write("You snap your fingers while whispering the magic word. "+ob->short()+" looks lighter!\n");
   } else {
     write("You cast the spell, but to no effect.\n");
   }
   say(this_player()->query_name()+" snaps his fingers and a small spark of light luminates "+ob->short()+".\n");
   return 1;
}
