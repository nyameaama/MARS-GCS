function [output] = returnmotorFLData()
    %Retrieve Velocity Data
    path = getDataPathFromConfig();
    % Specify the file path and name
    filePath = path;  % Replace with the path to your CSV file

    % Read the CSV file into a matrix
    data = readmatrix(filePath);
    
    % Specify the row and column indices to extract the data
    returnmotorFLDatarowIndex = 14;  % Replace with the desired row index
    returnmotorFLDatacolumnIndex = 2;  % Replace with the desired column index

    % Get the data from the specified row and column
    desiredData = data(returnmotorFLDatarowIndex,returnmotorFLDatacolumnIndex);
    output = desiredData;
end
