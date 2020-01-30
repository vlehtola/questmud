inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) return;
        set_level(150);
        set_name("Sorsa");
        set_short("Kaappi's SotkaSorsa");
        set_alt_name("Sorsa");
        set_alias("sorsa");
        set_long("Iso julma kotkasotka tai sorsa.\n");
        set_race("animal");
        set_gender(1);
}

catch_tell(str) {
 object ob, tgt;
 string dir, tmp, tmp2;
 if(sscanf(str, "Kaappi says '%s'", tmp2) == 1) {
  if(tmp2 == "mainos") {
   say("SotkaSorsa says: 'Nyt Sotkassa uusia kaappeja,sek� tietenkin.\n"+
       "ne kuuluisat patjanvaihtoviikot jatkuvat edelleen!\n");
   }

if(tmp2 == "irti") {
  this_object()->stop_fight();
  }
if(tmp2 == "seuraa") {
   say("Sotkasorsa KVAAKS.\n");
 }
}
if(sscanf(str,"Kaappi points at %s.", tmp2) == 1 || sscanf(str,"Kaappi says 'tapa %s'", tmp2) == 1) {
  tgt = present(lower_case(tmp2), environment(this_object()));
 attack_object(tgt);
 }
if(sscanf(str,"%s kiitt�� %s",tmp,dir) == 2 || sscanf(str,"Kaappi kiitt�� %s",tmp) == 1) {
   ob = find_player(lower_case(tmp));
   if(!ob) { return; }
    if(tmp == "Kaappi" || tmp == "kaappi") {
     call_out("move_to",1,ob);
  say("Sotkasorsa seuraa Master Kaappia.\n");
  }
 }
}
move_to(ob) {
 move_player("after " + ob->query_name(), environment(ob));
}
