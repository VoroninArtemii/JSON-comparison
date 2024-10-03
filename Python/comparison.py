import requests
import json

def compare(branch_1, branch_2):    
    
    response_1 = requests.get('https://rdb.altlinux.org/api/export/branch_binary_packages/' + branch_1)
    if (response_1.status_code != 200):
        print("Incorrect request! Try again!")
        return
    
    response_2 = requests.get('https://rdb.altlinux.org/api/export/branch_binary_packages/' + branch_2)
    if (response_2.status_code != 200):
        print("Incorrect request! Try again!")
        return
    
    json_1 = response_1.json()
    json_2 = response_2.json()
    
    i = 0
    j = 0
    json_1_only = []
    json_2_only = []
    json_1_more_version = []
    
    while (i != json_1["length"] and j != json_2["length"]):
        if (json_2["packages"][j]["arch"] < json_1["packages"][i]["arch"]):
            json_2_only.append(json_2["packages"][j])
            j = j + 1
            continue
        if (json_2["packages"][j]["arch"] > json_1["packages"][i]["arch"]):
            json_1_only.append(json_1["packages"][i])
            i = i + 1
            continue
        if (json_2["packages"][j]["name"] == json_1["packages"][i]["name"]):
            if (json_2["packages"][j]["version"] < json_1["packages"][i]["version"]):
                json_1_more_version.append(json_1["packages"][i])
            i = i + 1
            j = j + 1
        elif (json_2["packages"][j]["name"] > json_1["packages"][i]["name"]):
            json_1_only.append(json_1["packages"][i])
            i = i + 1
        else:
            json_2_only.append(json_2["packages"][j])
            j = j + 1
    
    with open('json_1_only.json', 'w') as file:
        json.dump(json_1_only, file)
    file.close()

    with open('json_2_only.json', 'w') as file:
        json.dump(json_2_only, file)
    file.close()

    with open('json_1_more_version.json', 'w') as file:
        json.dump(json_1_more_version, file)
    file.close()