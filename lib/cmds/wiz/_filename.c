cmd_filename(str) {
   object ob;
   if (!str) { write("Use: filename [object]\n"); return 1; }

   if(str == "room") ob = environment(this_player());
   else ob = present(str, environment(this_player()));

   if(!ob) ob = present(str, this_player());

   if (!ob) { write("No "+str+" here.\n"); return 1; }
   write("'"+ob->short()+"': '"+file_name(ob)+"'\n");
   return 1;
}

