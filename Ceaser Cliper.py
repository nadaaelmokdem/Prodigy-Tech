letters = 'abcdefghijklmnopqrstuvwxyz'
num_letters = len(letters)

def encrypt(text, key):
  ciphertext = ''
  for letter in text.lower():
    if letter.isalpha():  
      index = letters.find(letter)
      if index != -1:
        new_index = (index + key) % num_letters  
        ciphertext += letters[new_index]
      else:
        ciphertext += letter 
  return ciphertext

def decrypt(ciphertext, key):
  text = ''
  for letter in ciphertext.lower():
    if letter.isalpha():
      index = letters.find(letter)
      if index != -1:
        new_index = (index - key) % num_letters
        text += letters[new_index]
      else:
        text += letter
  return text

print()
print('Do you want to encrypt or decrypt?')
input_u = input('e or d:').lower()
print()

if input_u == 'e':
  while True:  
    try:
      key = int(input('Enter a key from 1 to 25: '))
      if 1 <= key <= 25:
        break
      else:
        print("Invalid key. Please enter a number between 1 and 25.")
    except ValueError:
      print("Invalid input. Please enter a number.")

  text = input('Enter the text you want to encrypt: ')
  ciphertext = encrypt(text, key)
  print(f'Encrypted: {ciphertext}')

elif input_u == 'd':
  while True:
    try:
      key = int(input('Enter a key from 1 to 25: '))
      if 1 <= key <= 25:
        break
      else:
        print("Invalid key. Please enter a number between 1 and 25.")
    except ValueError:
      print("Invalid input. Please enter a number.")

  text = input('Enter the text you want to decrypt: ')
  plaintext = decrypt(text, key)
  print(f'Decrypted: {plaintext}')

else:
  print("Invalid input. Please enter 'e' or 'd'.")
