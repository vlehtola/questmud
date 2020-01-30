inherit "obj/monster";
int i;

reset(arg) {
string chat_str;
::reset(arg);
i = 0;
if (arg) return;
set_level(33);
set_short("Momo the shadowcreeper");
set_name("Momo the shadowcreeper");
set_alias("momo");
 set_long(
 "His narrowed eyes sweep across the room for any danger. Sometimes he\n"+
"eyes sweeps across the room for any danger. Sometimes he\n"+
  "shivers violently but doesn't seem to be bothered\n"+
 "by your presence.\n");
set_race("human");
set_gender(1);
if (!chat_str) {
 chat_str = allocate(3);
chat_str[0] =
"Momo mutters: 'Yagh! Fresh air, bad air. I hate!'\n";
chat_str[1] =
"Momo says: 'Stupid shaman. Tried to lock me into that hole. I revenge!'\n";
chat_str[2] = "Momo says: 'Once I was tall and honorable. But that evil shaman cursed me!'\n";
}
load_chat(4, chat_str);
}

ask_question(str) {
        if(str == "sneek") {
  say("Momo says: 'I know.. Bad person.. Evil! Do me a favor first.'\n");
                return 1;
        }
if(str == "hut") {
say("Momo says: 'His hut is in the maze. Four spits to west and a turn to left.'\n");
return 1;
}
        if(str == "dwellers") {
                say("Momo yells: 'Cursed be those bastards!'\n");
return 1;
}
if(str == "maze") {
  say("Momo says: 'He is there, yesss he isss. I hate him. I hate shamans!'\n");
return 1;
}
if(str == "favor") {
  say("Momo says: 'Kill the shaman! Kill him and bring me his staff and I'll help you.'\n");
return 1;
}
if(str == "shaman") {
say("Momo says: 'He is cunning. Don't toy with him. That hut is a trap.'\n");
return 1;
}
        write("Momo tilts his head and shrugs.\n");
        return 1;
}

catch_tell(str) {
  object ob, boxi;
  string filu, tmp, tmp2;
  int id;
  if(sscanf(str, "%s gives %s to you.",tmp,tmp2) == 2) {
  if(i == 0) {
   ob = present("staff",this_object());
   if(ob) {
   if(sscanf(file_name(ob),"%s#%d",filu,id) == 2) {

    if(filu == "/wizards/rimber/cave/obj/staff") {
  boxi = clone_object("/wizards/rimber/cave/obj/box.c");
       say("Momo says: 'You killed him, you killed him!'\n");
      this_player()->set_quest("Kill the dweller shaman for Momo");
       say("Momo smiles wickedly and says: 'Take this as a gift. I don't know what to do with it'\n");
        write("Momo gives you a box.\n");
say("Momo says: 'And that Sneek. His hut is north, west, north, west and south from the white sign.'\n");
       move_object(boxi, this_player());
        call_out("tuho",1,ob);
       i = 1;
        return 1;
   }
 }
  }
}
}
}

//Added by Rag to prevent give from bugging
tuho(ob) {
  destruct(ob);
}
