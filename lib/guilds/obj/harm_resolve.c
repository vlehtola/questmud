harm_resolve(type, class, category, bonus, target, string god) {
  int pros, ob, dama, modifier;
  string str, tmp;
  if (!target) { write("This spell needs a target.\n"); return 1; }

    if (god == "morai") {
        modifier = 100 - (this_player()->query_god_status() / 5 * 3);
        god = "Morai";
        if (this_player()->query_god_status() > -30) {
           write("Nothing happens.\n");
           return 1;
        }
    }
    if (god == "cyral") {
	modifier = 65;
        god = "Cyral";
        if (this_player()->query_god_status() < 30) {
           write("Nothing happens.\n");
           return 1;
        }
    }


  ob = present(target, environment(this_player()));
  if (!ob) { write(target+" is not here.\n"); return 1; }

  if (bonus > 100) { bonus = (bonus - 100) / 4 + 100; }
  
  if (class != "hrm") {
	return;
  }

  if (type == "min") {  
        pros = 35;
        pros += bonus / 30;
        dama = ob->query_hp() * pros / 100;
        if (dama > 250) {
	    dama = 250;
	    write("You feel your spell reached its maximum effect.\n");
	}
        str = "Minor";
  }
  if (type == "les") {  
        pros = 35;
        pros += bonus / 30;
        dama = ob->query_hp() * pros / 100;
        if (dama > 500) {
	    dama = 500;
	    write("You feel your spell reached its maximum effect.\n");
	}
        str = "Lesser";
  }
  if (type == "mjr") {  
        pros = 30;
        pros += bonus / 30;
        dama = ob->query_hp() * pros / 100;
        if (dama > 950) {
	    dama = 950;
	    write("You feel your spell reached its maximum effect.\n");
	}
        str = "Major";
  }
  if (type == "gra") {
        pros = 30;
        pros += bonus / 30;
        dama = ob->query_hp() * pros / 100;
        if (dama > 1800) {
	    dama = 1800;
	    write("You feel your spell reached its maximum effect.\n");
	}
        str = "Greater";
  }
  if (type == "rea") {  
        pros = 30;
        pros += bonus / 30;
        dama = ob->query_hp() * pros / 100;
        if (dama > 3600) {
	    dama = 3600;
	    write("You feel your spell reached its maximum effect.\n");
	}
        str = "True";
  }
  if (modifier) {
	write("You feel " + god + " affecting you casting!.\n");
	dama = dama * modifier / 100;
  }
  write("You hit "+target+" with a "+str+" Harm!\n");
  tell_object(ob, this_player()->query_name()+" hits you with a "+str+" Harm!\n");  
  say(this_player()->query_name()+" hits "+ob->query_name()+" with a "+str+" Harm!\n",ob);
  this_player()->attack_object(ob,1);
  ob->hit_with_spell(dama,0, this_player());
  this_player()->casting_sp_reduce(dama / 6);
  return 1;
}
