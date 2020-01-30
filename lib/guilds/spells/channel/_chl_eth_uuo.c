resolve(bonus, target) {
   object ob,tmp;
   int effect;
   if (!target) { write("Cast spell on who?\n"); return; }
   ob = find_player(lower_case(target));
   if (!ob || !present(ob,environment(this_player()))) {
     write("No "+capitalize(target)+" here.\n"); return 1; }
   tmp = clone_object("/guilds/spell_obj/undeath");
   effect = 20;
   effect += this_player()->query_skills("cast soul") / 7;
   effect += this_player()->query_skills("cast life") / 4;
   if (effect > 65) { effect = 65; }

   tmp->start(ob,effect);
   write("You shield "+capitalize(target)+" with the aura of life.\n");
   say(capitalize(target)+" starts to emit a peaceful white glow.\n",ob);
   tell_object(ob, "You feel an unearthly will to live in your whole body!\n");
}
