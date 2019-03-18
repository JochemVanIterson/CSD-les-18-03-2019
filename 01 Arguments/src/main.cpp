#include <getopt.h>
#include <string>
#include <iostream>

std::string filename = "";
int jackOutputs = 0;
bool verbose = false;

void getArguments(int *argc, char **argv[]){
  int c;

  while (1) {
    int option_index = 0;
    static struct option long_options[] = {
      {"file",     required_argument, 0,  'f' },
      {"mode",     required_argument, 0,  'm' },
      {"jackOut",  required_argument, 0,  'j' },
      {"verbose",  no_argument,       0,  1 },
      {"help",     no_argument,       0,  'h' },
      {0,          no_argument,       0,  'k' },
      {0,          0,                 0,  0 }
    };

    c = getopt_long((*argc), (*argv), "hf:m:j:k01", long_options, &option_index);
    if (c == -1)
      break;

    switch (c) {
      case 0:
        printf("option %s", long_options[option_index].name);
        if (optarg)
          printf(" with arg %s", optarg);
        printf("\n");
        break;
      case 'k':
        std::cout << "Letter K" << '\n';
        break;
      case 'f':
        filename = optarg;
        break;
      case 'o':
        jackOutputs = std::atoi (optarg);
        break;
      case 'h':
        std::cout << "Usage: convolution\n\t";
        std::cout << "[-f | --file <filepath>] ";
        std::cout << "[-h | --help] ";
        std::cout << "[-i | --impulse <filepath>]\n\t";
        std::cout << "[-m | --mode <'direct_mic' | 'direct_file' | 'impulse_mic' | 'impulse_file'>]\n\t";
        std::cout << "[--verbose]\n\n";

        exit(EXIT_SUCCESS);
        break;
      case 1:
        verbose = true;
        break;

      case '?':
        break;

      default:
        printf("?? getopt returned character code 0%o ??\n", c);
    }
  }

  if (optind < (*argc)) {
    printf("non-option ARGV-elements: ");
    while (optind < (*argc))
      printf("%s ", (*argv)[optind++]);
      printf("\n");
  }
}

int main(int argc, char** argv) {
  getArguments(&argc, &argv);
}
