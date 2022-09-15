def nato(words: str):
  words = words.replace(" ", "");
  natoAlpha = {
    'a': 'alfa',
    'b' : 'bravo',
    'c' : 'charlie',
    'd' : 'delta',
    'e' : 'echo',
    'f' : 'foxtrot',
    'g' : 'golf',
    'h' : 'hotel',
    'i' : 'indigo',
    'j' : 'juliett',
    'k' : 'kilo',
    'l' : 'lima',
    'm' : 'mike',
    'n' : 'november',
    'o' : 'oscar',
    'p' : 'papa',
    'q' : 'quebec',
    'r' : 'romeo',
    's' : 'sierra',
    't' : 'tango',
    'u' : 'uniform',
    'v' : 'victor',
    'w' : 'whiskey',
    'x' : 'x-ray',
    'y' : 'yankee',
    'z' : 'zulu'
  }
  for c in words :
    print(natoAlpha[c]);


def braille(words):
  words = words.replace(" ", "");
  brailleAlpha = {
    'a': '*-',
    'b' : '-***',
    'c' : '-*-*',
    'd' : '-**',
    'e' : '*',
    'f' : '**-*',
    'g' : '--*',
    'h' : '****',
    'i' : '**',
    'j' : '*---',
    'k' : '-*-',
    'l' : '*-**',
    'm' : '--',
    'n' : '-*',
    'o' : '---',
    'p' : '*--*',
    'q' : '--*-',
    'r' : '*-*',
    's' : '***',
    't' : '-',
    'u' : '**-',
    'v' : '***-',
    'w' : '*--',
    'x' : '-**-',
    'y' : '-*--',
    'z' : '--**'
  }
  for c in words:
    print(brailleAlpha[c]);


def interestCalc():
  initialBalance = float(input("Initial balance: "))
  annualInterest = float(input("Annual interest rate: "))
  monthlyInterest = annualInterest / 12 / 100;
  firstMonth = initialBalance * (1 + monthlyInterest)
  secondMonth = initialBalance * (1 + 2 * monthlyInterest)
  thirdMonth = initialBalance * (1 + 3 * monthlyInterest)
  print("After first month: ", round(firstMonth, 2))
  print("After second month: ", round(secondMonth,2))
  print("After third month: ", round(thirdMonth,2))


interestCalc();
# nato('hello');
