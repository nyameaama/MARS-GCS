function [output] = returnAngleXdata()
    %Retrieve Velocity Data
    path = getDataPathFromConfig();
    % Specify the file path and name
    filePath = path;  % Replace with the path to your CSV file

    % Read the CSV file into a matrix
    data = readmatrix(filePath);
    
    % Specify the row and column indices to extract the data
    AngleXrowIndex = 11;  % Replace with the desired row index
    AngleXcolumnIndex = 2;  % Replace with the desired column index

    % Get the data from the specified row and column
    desiredData = data(AngleXrowIndex,AngleXcolumnIndex);
    output = desiredData;
end

