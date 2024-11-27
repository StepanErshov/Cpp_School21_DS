import json

api_token = {"username":"stepanershov","key":"4ba4e4e6764532648c7cc0f089df11b9"}
with open('C:/Users/79245/.kaggle/kaggle.json', 'w') as file:
    json.dump(api_token, file)