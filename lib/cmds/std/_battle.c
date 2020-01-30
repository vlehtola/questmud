//Command for setting misc battle stuff
//Only battle round flag atm.

cmd_battle(str) {
  string tmp, rounds;
                                                                                                       
  if(!str) {
   write("See help battle for the correct usage.\n");
   return 1;
  }

  rounds = this_player()->query_battle("round");

  if(str == "round") {
   if(rounds) {
        write("Your battle round flag is set to: "+rounds);
        return 1;
   } else {
        write("You have not set your battle round flag.\n");
        return 1;
   }
  }

  if(str == "round clear") {
   this_player()->clear_battle("round");
   write("Battle round flag cleared.\n");
   return 1;
  }
                                                                                                       
  if(sscanf(str,"round %s",tmp) == 1) {
                                                                                                       
   if(strlen(tmp) > 20) {
        write("The maximum length for the round flag is 20 characters.\n");
        return 1;
   }

   tmp += "\n";

   this_player()->set_battle("round",tmp);
   write("Battle round flag set to: "+tmp);
   return 1;
  }
                                                                                                       
  if(str == "brief") {
    this_player()->set_bbrief();
    return 1;
  }
                                                                                                       
  write("See help battle for the correct usage.\n");
  return 1;
}
                                                                                                       

