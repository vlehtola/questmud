//Compare skill by Rag 1.7.2004
//Can be used to compare 2 weapons or 2 armours
//Right results only with 100% skill

//Compare two weapons
weapons(object ob1, object ob2) {
  int error, wc1, wc2, hb1, hb2, weight1, weight2, value1, value2;
  string str1, str2;
  
  error = 100-this_player()->query_skills("compare");
  
  str1 = ob1->short();
  str2 = ob2->short();
  
  weight1 = ob1->query_weight() + random(error);
  weight2 = ob2->query_weight() + random(error);
  wc1 = ob1->query_wc() + random(error);
  wc2 = ob2->query_wc() + random(error);
  hb1 = ob1->query_hit_bonus() + random(error);
  hb2 = ob2->query_hit_bonus() + random(error);
  value1 = ob1->query_value() + random(error);
  value2 = ob2->query_value() + random(error);
  
  if ( weight1 > weight2 ) {
  	write(str1+" seems to be heavier than "+str2+".\n");
  } else if ( weight1 < weight2 ){
  	write(str1+" seems to be lighter than "+str2+".\n");
  } else {
  	write(str1+" and "+str2+" don't differ in weight.\n");
  }
  
  if ( wc1 > wc2 ) {
  	write(str1+" deals more damage than "+str2+".\n");
  } else if ( wc1 < wc2 ) {
  	write(str1+" deals less damage than "+str2+".\n");
  } else {
  	write(str1+" and "+str2+" are equal in damage.\n");
  }
  
  if ( hb1 > hb2 ) {
  	write(str1+" would hit your targets better than "+str2+".\n");
  } else if ( hb1 < hb2 ) {
  	write(str1+" would hit your targets worse than "+str2+".\n");
  } else {
  	write(str1+" and "+str2+" have the same chance to hit your targets.\n");
  }
  
  if ( value1 > value2 ) {
  	write(str1+" is worth more than "+str2+".\n");
  } else if ( value1 < value2 ) {
  	write(str1+" is worth less than "+str2+".\n");
  } else {
  	write(str1+" and "+str2+" are equally valuable.\n");
  }
  
  return 1;
}

//Compare armours
armours(object ob1, object ob2) {
  int error, ac1, ac2, weight1, weight2, value1, value2;
  string str1, str2;
  
  error = 100-this_player()->query_skills("compare");
  
  str1 = ob1->short();
  str2 = ob2->short();
  
  weight1 = ob1->query_weight() + random(error);
  weight2 = ob2->query_weight() + random(error);
  ac1 = ob1->query_ac() + random(error);
  ac2 = ob2->query_ac() + random(error);
  value1 = ob1->query_value() + random(error);
  value2 = ob2->query_value() + random(error);
  
  if ( ob1->query_slot() == ob2->query_slot() ) {
  	write(str1+" and "+str2+" fit in the same slot.\n");
  } else {
  	write(str1+" and "+str2+" go to different slots.\n");
  }
  
  if ( weight1 > weight2 ) {
  	write(str1+" seems to heavier than "+str2+".\n");
  } else if ( weight1 < weight2 ){
  	write(str1+" seems to lighter than "+str2+".\n");
  } else {
  	write(str1+" and "+str2+" don't differ in weight.\n");
  }
  
  if ( ac1 > ac2 ) {
  	write(str1+" would give more protection than "+str2+".\n");
  } else if ( ac1 < ac2 ) {
  	write(str1+" would give less protection than "+str2+".\n");
  } else {
  	write(str1+" and "+str2+" are equal in protection.\n");
  }
  
  if ( value1 > value2 ) {
  	write(str1+" is worth more than "+str2+".\n");
  } else if ( value1 < value2 ) {
  	write(str1+" is worth less than "+str2+".\n");
  } else {
  	write(str1+" and "+str2+" are equally valuable.\n");
  }
  
  return 1;
}

get_time() {
  return 5;
}

ep_cost() {
  return 0;
}
query_type() { return "neutral"; }

resolve_skill(str) {
  object ob1, ob2;
	string str1, str2;
  
  if (!str) {
    write("Use compare at what?\n");
    return 1;
  }

  if ( sscanf(str,"%s and %s",str1,str2) != 2 ) {
  	write("You must specify two items by using compare at item1 and item2.\n");
  	return 1;
 	}

  ob1 = present(str1, this_player());
  ob2 = present(str2, this_player());
  if( !ob1 ) {
   write("You don't have any "+str1+".\n");
   return 1;
  }
  if( !ob2 ) {
   write("You don't have any "+str2+".\n");
   return 1;
  }
  
  if( ob1->query_wc() ) {
  	if ( ob2->query_wc() ) {
  		write("Comparing "+ob1->short()+" with "+ob2->short()+".\n");
  		weapons(ob1, ob2);
  		return 1;
  	}
  }
  
  if( ob1->query_ac() ) {
  	if ( ob2->query_ac() ) {
  		write("Comparing "+ob1->short()+" with "+ob2->short()+".\n");
  		armours(ob1, ob2);
  		return 1;
  	}
  }
	write("You can only compare weapons with weapons or armours with armours.\n");
  return 1;
}

fail_skill(str) {
  write("You can't figure anything out from these items.\n");
}

