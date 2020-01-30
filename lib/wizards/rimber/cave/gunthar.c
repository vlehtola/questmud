inherit "obj/monster";
int a = 0;

reset(arg) {
object weapon;
 object armour;
 string chat_str;
::reset(arg);
 if(arg) { return; }
set_short("Gunthar");
set_name("Gunthar von Marichten, an old cave explorer");
set_alias("gunthar");
 set_long("Gunthar has dirty clothes and tangled hair.\n"+
 "Piece of paper lie around him and every time he moves\n"+
 "they make sharp rustling sound.\n");
set_level(43);
set_skill("strike", 100);
set_race("human");
set_gender(1);
 if(a == 0) {
weapon = clone_object("/wizards/rimber/cave/obj/sword.c");
move_object(weapon, this_object());
init_command("wield longsword");
armour = clone_object("/wizards/rimber/cave/obj/bracut.c");
move_object(armour, this_object());
init_command("wear bracelets");
 }
set_log();
if (!chat_str) {
chat_str = allocate(2);
 if(a == 0) { chat_str[0] = "Gunthar mutters: 'Damn those dwellers. Why don't they let me finish my map?'\n"; }
 else { chat_str[0] = "Gunthar says: 'Now that the map is finished I can rest.'\n"; }
chat_str[1] =
"Gunthar says: 'That maze is absolutely amazing!'\n";
}
 load_chat(2, chat_str);
}

ask_question(str) {
        if(str == "map") {
 say("Gunthar says: 'I've almost finished it. If I just had the permission to finish it.'\n");
                return 1;
        }
if(str == "permission") {
 say("Gunthar says: 'A dweller called Sneek controls the maze. I need his permission to finish my map.'\n");
return 1;
}
if(str == "sneek") {
 say("Gunthar says: 'I don't know how to find him. Maybe somebody else knows.'\n");
return 1;
}
        if(str == "dwellers") {
 say("Gunthar says: 'Watch out for them. They are mean and ruthless.'\n");
                return 1;
        }
if(str == "maze") {
 say("Gunthar says: 'Many, many, many good fellows of mine have died in there.'\n");


return 1;
}
        if(str == "momo") {
                say("Gunthar says: 'I know much about him. He is the oldest person in here.'\n");
                return 1;
        }
        write("Gunthar asks: 'What are you talking about'\n");
        return 1;
}

catch_tell(str) {
 object ob;
 string filu, tmp, tmp2;
 int id;
  if(sscanf(str, "%s gives %s to you.",tmp,tmp2) == 2) {
   ob = present("letter", this_object());
   if(ob) {
   if(sscanf(file_name(ob),"%s#%d",filu,id) == 2) {
    if(filu == "/wizards/rimber/cave/obj/letter") {
     destruct(ob);
     say("Gunthar says: 'Oh, thank you! Now I can finish my map.'\n");
     say("Gunthar starts writing.\n");
    a = 1;
     call_out("delay_map", 6);
     return 1;
  }
 }
}
}
}

int delay_map() {
 say("Gunthar writes last words and finishes the map.\n");
 say("Gunthar says: 'Now it's done. Here, I give you a copy.'\n");
 write("Gunthar gives you a map.\n");
 move_object("/wizards/rimber/cave/obj/map.c", this_player());
 this_player()->set_quest("Help Gunthar finish his map");
  reset();
}
