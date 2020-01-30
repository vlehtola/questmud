cmd_use(string str) {
  object skill, spell;
  skill = this_player()->query_use_skill();
  spell = this_player()->query_spell();
  if (!this_player()->check_condis()) { return 1; }
  if (environment(this_player())->query_property("no_skill")) {
    write("A mystical aura stops your attempt.\n");
    return 1;
  }
  if (!str) { 
    write("Usage: use <skill> [at <target>]\n");
    return 1;
  }
// added by C 20.5.04. duration is 40s when max time is 5mins
  if(this_player()->query_max_death_legacy_time() *6/7 < this_player()->query_death_legacy_time()) {
    write("You are still not fully recovered from resurrection.\n");
    return 1;
  }


  if (str == "stop") {
    if (skill) {
      write("You stop your skill attempt.\n");
      skill->interrupt_skill();
      return 1;
    } else {
      write("You are not doing anything.\n");
      return 1;
    }
  }
  if (skill) {
    write("You decide to start a new skill.\n");
    destruct(skill);
  }
  if (spell) {
    write("You stop your casting and start to concentrate on a skill.\n");
    destruct(spell);
   }

  skill = clone_object("/guilds/obj/skill");
  this_player()->set_use_skill(skill);
  skill->start_skill(str);
  return 1;  
}   

