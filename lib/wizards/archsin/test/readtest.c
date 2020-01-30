string *file;
mixed x;
int *num;

void reset() {
  x = allocate(4);
  x[0] = allocate(30);
  x[1] = allocate(30);
  x[2] = allocate(30);
  x[3] = allocate(30);
  num = allocate(10);
}

void parse() {
  int a, b, i;
  string c;
  sscanf(file[0], "num[%d] = %d", a, b);
  num[a] = b;
  for(i=1; i<sizeof(file); i++) {
    sscanf(file[i], "test[%d][%d] = %s", a, b, c);
    write("test["+a+"]["+b+"] = "+c+"\n");
    x[a][b] = c;
    write("x["+a+"]["+b+"] = "+x[a][b]+"\n");
  }
}

int test() {
  int i;
  file = explode(read_file("/wizards/archsin/test/foo.bar"), "\n");
  write(sizeof(file)+"\n");
  for(i=0; i<sizeof(file); i++) {
    write(file[i]+"\n");
  }
  write("calling parse: \n");
  parse();
  return 1;
}

