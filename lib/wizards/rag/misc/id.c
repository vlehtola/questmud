#define WST "/daemons/weapon_sub_types"

short() { return "Rag's identifier"; }

long() {
  write("Usage: identify <weapon>\n");
  return 1;
}

id(str) { return str == "identifier"; }

init() {
  add_action("ide","identify");
}

get() { return 1; }

ide(str) {
  object ob;
  string type, general_type;

  if(!this_player()->query_wiz()) {
        write("Your mortal mind is too weak to handle the identifier!\n");
        this_player()->death();
        if(find_player("rag")) {
                tell_object(find_player("rag"),this_player()->query_name()+
                " tried to use the identifier!\n");
        }
        return 1;
  }

  if(!str) {
        write("Error!\n");
        return 1;
  }

  ob = present(str,this_player());
  if(!ob) ob = present(str,environment(this_player()));
  if(!ob) {
        write("Error!\n");
        return 1;
  }

  type = ob->query_sub_type();
  general_type = ob->query_type();

  write(ob->short());
  write("\nType: "+general_type);
  write("\nSubtype: "+type);
  write("\nWC: "+ob->query_wc());
  write("\nHB: "+WST->query_hit_bonus(type)+" / "+ob->query_hit_bonus(this_player()->query_str()));
  write("\nDB: "+WST->query_damage_bonus(type));
  write("\nBash: "+WST->query_damage_amount(type, "bash"));
  write("\nSlash: "+WST->query_damage_amount(type, "slash"));
  write("\nPierce: "+WST->query_damage_amount(type, "pierce"));
  write("\n");
  return 1;
}
