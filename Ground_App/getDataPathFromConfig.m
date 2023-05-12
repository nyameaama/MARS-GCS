function [output] = getDataPathFromConfig()
    % Open the text file
    filePath = 'config.txt'; % Replace with the path to your text file
    fileID = fopen(filePath, 'r');

    % Initialize variables
    refDataPath = ''; % Variable to store the extracted data

    % Read the file line by line
    tline = fgetl(fileID);
    while ischar(tline)
        % Search for the string "REF_DATA_PATH"
        idx = strfind(tline, 'REF_DATA_PATH');
        if ~isempty(idx)
            % Extract the data assigned to "REF_DATA_PATH" using "=" and ";"
            dataStartIdx = strfind(tline, '=') + 1;
            dataEndIdx = strfind(tline, ';') - 1;
            refDataPath = strtrim(tline(dataStartIdx:dataEndIdx));
            break; % Exit the loop after finding the data
        end

        % Read the next line
        tline = fgetl(fileID);
    end

    % Close the file
    fclose(fileID);
    output = refDataPath;
end

