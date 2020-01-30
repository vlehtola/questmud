get_time() {
  if(this_player()->query_npc()) return 5;
return random(3)+3;
}
query_type() { return "neutral"; }

ep_cost() { return 2; }

resolve_skill(str, object ob) {
    if(!ob)ob=this_player();
    if(!ob->query_right_weapon()) {
        write("You need to wield sorcerers staff in your right hand to use this skill.\n");
        return 1;
    }
    if (this_player()->query_attack()) {
        write("You cannot teleport while in combat.\n");
        return 1;
    }
    if( ob->query_right_weapon()->query_name() != "club") {
        write("You need to wield your staff in your right hand to use this skill.\n");
        return 1;
    }


}

fail_skill() {
   write("You fail the spell.\n");
    say(this_player()->query_name()+" stops chanting but nothing happens.\n");
}

