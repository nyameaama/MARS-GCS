function [output] = returnPitchData()
    %Retrieve Velocity Data
    path = getDataPathFromConfig();
    % Specify the file path and name
    filePath = path;  % Replace with the path to your CSV file

    % Read the CSV file into a matrix
    data = readmatrix(filePath);
    
    % Specify the row and column indices to extract the data
    PitchrowIndex = 7;  % Replace with the desired row index
    PitchcolumnIndex = 2;  % Replace with the desired column index

    % Get the data from the specified row and column
    desiredData = data(PitchrowIndex,PitchcolumnIndex);
    output = desiredData;
end