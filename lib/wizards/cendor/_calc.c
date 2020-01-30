
#undef DEBUG

mixed to_int(string str) {
  mixed arvo;
  if(str != "0" && str != "0.0" ) {
    arvo = efun::to_float(str);
    if(arvo == 0.0)
      arvo = str;
  }
  else arvo = 0.0;
  return arvo;
}
int sulkuja(string str) {
  int i;
  for(i=0;i<strlen(str);i++) {
    if(str[i] == '(' || str[i] == ')') return 1;
  }
  return 0;
}

strip(string str) {
  string *allowed, tmp;
  int i;
  tmp = "";
  allowed = ({ '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
        '(', ')', '*', '/', '+', '-', '.', '^' });

  for(i=0;i<strlen(str);i++) {
    if(member(allowed, str[i])!=-1) tmp += str[i..i];
  }
  return tmp;
}

potenssi(float a, float b) {
  int i, index;
  float result;

  result = to_float(a);
  index = (int)b;
  for(i=0;i<index-1;i++) {
     result = result * a;
  }
  return result;
}

laske(string str) {
  string *kalat;
  int i, indeksi;

#ifdef DEBUG
  write("Calculating " + str + ".\n");
#endif
  if(!str) return 0;
  if(!stringp(str) && intp(str))
    return str;
  indeksi = 0;
  kalat = ({ "" });
  for(i=0;i<strlen(str);i++) {
    switch(str[i]) {
      case '+': case '-': case '/': case '*': case '^':
        kalat += ({ str[i..i] });
        kalat += ({ "" });
        indeksi+=2;
        break;
      default:
        kalat[indeksi] = kalat[indeksi] + str[i..i];
        break;
    }
  }
#ifdef DEBUG
  write(sprintf("%-O\n", kalat));
#endif
  for(i=0;i<sizeof(kalat);i++) {
    kalat[i] = to_int(kalat[i]);
  }
#ifdef DEBUG
  write(sprintf("%-O\n", kalat));
#endif
  while(sizeof(kalat)>1) {
    for(i=0;i<sizeof(kalat);i++) {
      if(stringp(kalat[i])) {
        switch(kalat[i]) {
          case "^":
            if(sizeof(kalat)>i+1 && i>0) {
               kalat[i+1] = potenssi(kalat[i-1], kalat[i+1]);
               kalat[i-1] = "to_remove"; kalat[i] = "to_remove";
            }
            break;
          case "*":
            if(sizeof(kalat)>i+1 && i>0) {
              kalat[i+1] = kalat[i-1]*kalat[i+1];
              kalat[i-1] = "to_remove"; kalat[i] = "to_remove";
            }
            break;
          case "/":
            if(sizeof(kalat)>i+1 && i>0) {
              kalat[i+1] = kalat[i-1]/kalat[i+1];
              kalat[i-1] = "to_remove"; kalat[i] = "to_remove";
            }
            break;
        }
      }
    }
    for(i=0;i<sizeof(kalat);i++) {
      if(stringp(kalat[i])) {
        switch(kalat[i]) {
          case "+":
            if(sizeof(kalat)>i+1 && i>0) {
              kalat[i+1] = kalat[i-1]+kalat[i+1];
              kalat[i-1] = "to_remove"; kalat[i] = "to_remove";
            }
            break;
          case "-":
            if(sizeof(kalat)>i+1 && i>0) {
              kalat[i+1] = kalat[i-1]-kalat[i+1];
              kalat[i-1] = "to_remove"; kalat[i] = "to_remove";
            }
            break;
        }
        
      }
      kalat -= ({ "to_remove" });
    }
  }
#ifdef DEBUG
  write(sprintf("%-O\n", kalat));
  write("Got " + kalat[0] + ".\n");
#endif
  return kalat[0];
}

sulut(string str) {
  int i;
  int alkaa, counter;

#ifdef DEBUG
  write("Removing () from " + str + ".\n");
#endif
  counter = 0;
  for(i=0;i<strlen(str);i++) {
    switch(str[i]) {
      case '(':
        if(counter==0) {
          alkaa = i;
        }
        else counter++;
        break;
      case ')':
        if(counter==0) {
          catch(str = str[0..(alkaa)-1]+laske(str[(alkaa+1)..(i-1)])+str[(i+1)..]);
        }
        else counter--;
        break;
    }
  }
  return str;
}

floatosa(float fl) {
  int i;
  i = (int)fl;
  return to_float(to_string(fl-i)[0..5]);
}

kokonaisosa(float fl) {
  return (int)fl;
}

tarkista(float fl) {
  int i, j;
  string ret;
  float res;

  for(i=2;i<10;i++) {
    for(j=1;j<10;j++) {
      if(j%i!=0 && floatosa((float)fl) == floatosa((float)j/i)) {
        if(kokonaisosa(fl) != 0) ret = kokonaisosa(fl) + " ";
        else ret = "";
        ret +=  j+"/"+i;
        return ret;
      }
    }
  }
  return 0;
}

cmd_calc(string str) {
  float result;
  string tmp;
  tmp = str;
  str = strip(str);
  write(str + " = ");
  while(sulkuja(str)) {
    str = sulut(str);
  }

  catch(result = laske(str));
  if(str != tmp)
    write(str + " = ");
  write(result);
  str = tarkista(result);
  if(str) write(" (" + str + ")\n");
  else write(".\n");
  return 1;
}

string do_help() {
  return "\
Command: calc\n\
Arguments: mathematical expression\n\
\n\
This command tries to calculate the given expression.\n\
Examples: calc 5+2\n\
          calc 2*(2+5)\n\
          calc 3^3\n";
}


