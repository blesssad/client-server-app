#include "error.hpp"

void split_str(string& word, string& file_name, char* buffer)
{
    int flag = 0;
    //cout << buffer << endl;
    for(int i = 0; i < strlen(buffer); ++i)
    {
        // if(buffer[i] == '\'' && buffer[i + 1] == 'n')
        //     break;
        if(buffer[i] == ' ')
        {
            flag++;
            i++;
        }
        if(flag == 0)
            word += buffer[i];
        else
            file_name += buffer[i];
    }
}

string count_of_words(char* buffer)
{
    string word, file_name, text, temp_str;
    char symbol;
    int temp = 0, count = 0;
    
    split_str(word, file_name, buffer);
    ifstream file(file_name); 
    if(file.is_open())
    {
        text = word + " ";
        while(getline(file, temp_str))
        {   
            text += temp_str;
            text += " ";
        }
        
     
        vector<int> prefixes(text.size());
        prefixes[0] = 0;

        for (int i = 1; i <= text.length()-1; i++)
        {
            if(text[i] == text[prefixes[i-1]])
            {
                prefixes[i] = prefixes[i-1] + 1;
            }
            else
            {
                temp = prefixes[i-1];
                while(temp > 0 && text[i] != text[temp])
                {
                    temp = prefixes[temp-1];
                    if(text[i] == text[temp])
                    {
                        prefixes[i] = temp + 1;
                        break;
                    }
                }
            }
        }

        for(int i = word.length(); i <= text.length()-1; i++)
        {
            if(word.length() == prefixes[i])
            {
                count += 1;
            }
        }

        cout << "Your file is fine" << endl; 
        temp_str = to_string(count);
        
    }
    else
    {
        cout << "Your file is broke" << endl; 
        temp_str = "Your file is broke";
    } 
    
    return temp_str;
}